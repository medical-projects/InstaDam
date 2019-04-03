#ifndef INSTADAM_H
#define INSTADAM_H

#include <stdio.h>

#include <QFile>
#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDialog>
#include <QGraphicsItem>
#include <QUndoGroup>
#include <QObject>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
#include <QBuffer>
#include <QUndoStack>

#include <iostream>
#include <string>

#include "newproject.h"
#include "picpushbutton.h"
#include "ui_blankFrame.h"
#include "ui_freeSelect.h"
#include "ui_polygonSelect.h"
#include "../Selector/label.h"
#include "labelButton.h"
#include "enumconstants.h"
#include "project.h"
#include "Selector/photoScene.h"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"

class filterControls;
class PicPushButton;

namespace Ui {
class InstaDam;
}

class InstaDam : public QMainWindow {
    Q_OBJECT

 public:
    explicit InstaDam(QWidget *parent = nullptr);
    ~InstaDam();
    void fileOpen();
    void connectFilters();
    filterControls * filterControl;

    int fileId = 0;
    QFileInfo file, oldFile;
    QString filename, oldFilename;
    QString labelFile;

    QVector<QString> labelPaths, oldLabelPaths;
    QString annotationPath, oldAnnotationPath;
    QStringList imagesList, oldImagesList;
    QDir path, oldPath;
    void openFile_and_labels();
    void setLabels();
    void generateLabelFileName();
    void assertError(std::string errorMessage);
    void exportImages(bool asBuffers = false);
    void clearLayout(QLayout * layout);
    QList<maskTypes> maskTypeList;
    QList<PicPushButton*> maskButtonList;

 private slots:
    void on_addSelectionButton_clicked();
    void on_saveAndBack_clicked();
    void on_actionSave_Annotation_triggered();
    void on_actionOpen_File_triggered();
    void on_rectangleSelectButton_clicked();
    void on_ellipseSelectButton_clicked();
    void on_polygonSelectButton_clicked();
    void on_freeSelectButton_clicked();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_pushButton_14_clicked();
    void on_actionExport_triggered();
    void on_actionExport_zip_triggered();
    void on_saveAndNext_clicked();

    void setInsert();
    void toggleDrawing();
    void toggleErasing();
    void setCurrentLabel(QSharedPointer<Label> label);
    void setCurrentLabel(LabelButton *button);
    void setOpacity(QSharedPointer<Label>, int val);
    void setCurrentBrushSize(int);
    void setNewProject();
    void addCurrentSelection();
    void cancelCurrentSelection();
    void finishPolygonButtonClicked();
    void panButton_clicked();
    void roundBrushButtonClicked();
    void squareBrushButtonClicked();

    void processMouseMoved(QPointF fromPos, QPointF toPos);
    void processPointClicked(PhotoScene::viewerTypes type, SelectItem *item,
                             QPointF pos, const Qt::MouseButton button);
    void processMouseReleased(PhotoScene::viewerTypes type, QPointF oldPos,
                              QPointF newPos, const Qt::MouseButton button);
    void processKeyPressed(PhotoScene::viewerTypes type, const int key);
    void processShowHide(int state);

 public slots:
    void resetPixmapButtons();


 private:
#ifdef WASM_BUILD
    struct MyConnector{
            std::function<void(void)> onActivate;
    };
    void loadRawImage();
    void addImageConnector(QString text, std::function<void(void)> onActivate);
    void addIdproConnector(QString text, std::function<void(void)> onActivate);
    MyConnector *openImageConnector;
    MyConnector *openIdproConnector;
    QByteArray imageFileContent;
    QByteArray idproFileContent;
#endif
    QSharedPointer<Label> currentLabel;
    QVector<LabelButton*> labelButtons;
    Ui::InstaDam *ui;
    newproject *newProject;
    Project *currentProject = nullptr;
    PhotoScene *scene;
    PhotoScene *maskScene;
    QUndoStack *mainUndoStack;
    QUndoStack *tempUndoStack;
    QUndoGroup *undoGroup;
    SelectItem::SelectType currentSelectType;
    SelectItem *currentItem;
    QAction *undoAction;
    QAction *redoAction;
    QByteArray imgData;
    QString idproFileName;
    QWidget *blankWidget;
    QWidget *freeSelectWidget;
    QWidget *polygonSelectWidget;
    QGridLayout *controlLayout;
    Ui::blankForm *blankForm;
    Ui::freeSelectForm *freeSelectForm;
    Ui::polygonSelectForm *polygonSelectForm;
    bool drawing = true;
    bool panning = false;
    bool canDrawOnPhoto = true;
    int lastType = -1;
    bool insertVertex = false;
    int vertex1 = -1;
    int vertex2 = -1;
    int currentBrushSize = 5;
    FreeDrawErase *myErase;
    SelectItem *tempItem;
    SelectItem *mirrorItem;
    SelectItem *maskItem;
    Qt::PenCapStyle brushMode = Qt::RoundCap;
    Qt::MouseButton currentButton = Qt::NoButton;
    QHash<QString, QBuffer*> exportFiles;
    QVector<QSharedPointer<Label> > tempLabels;

    QPixmap maskSelection(SelectItem *item);
    bool read(const QJsonObject &json, fileTypes type = PROJECT);
    void write(QJsonObject &json, fileTypes type = PROJECT);
    bool loadLabelFile(QString filename, fileTypes fileType);
    QStringList getLabelNames(QVector<QSharedPointer<Label> > labels);
    void revert();
};

#endif  // INSTADAM_H
