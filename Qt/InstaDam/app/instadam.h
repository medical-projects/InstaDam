#ifndef INSTADAM_H
#define INSTADAM_H

#include <QFile>
#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "project.h"
#include <QDialog>
#include <QGraphicsItem>
#include <QObject>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>

#include "newproject.h"
#include "ui_blankFrame.h"
#include "ui_freeSelect.h"
#include "ui_polygonSelect.h"
#include "../Selector/label.h"
#include "labelButton.h"

#include <iostream>
#include <string>
#include <stdio.h>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc.hpp"

class filterControls;

enum maskTypes{CANNY, THRESHOLD, BLUR, OTHER};
enum threshold_or_filter{THRESH, FILTER};
#include <QUndoStack>

#include "Selector/photoScene.h"


namespace Ui {
class InstaDam;
}

class InstaDam : public QMainWindow
{
    Q_OBJECT

public:
    explicit InstaDam(QWidget *parent = nullptr);
    ~InstaDam();
    void fileOpen();
    void connectFilters();
    filterControls * filterControl;

    int fileId= 0;
    QFileInfo file;
    QString filename;
    QString labelFile;
    QStringList imagesList;
    QDir path;
    void openFile_and_labels();
    void generateLabelFileName();
    void assertError(std::string errorMessage);
    void saveFile();
    void clearLayout(QLayout * layout);

private slots:
    void on_actionOpen_File_triggered();
    void on_rectangleSelectButton_clicked();
    void on_ellipseSelectButton_clicked();
    void on_polygonSelectButton_clicked();
    void on_freeSelectButton_clicked();
    void processMouseMoved(QPointF fromPos, QPointF toPos);
    void processPointClicked(viewerTypes type, SelectItem *item, QPointF pos);
    void processLeftMouseReleased(viewerTypes type, QPointF oldPos, QPointF newPos);
    void processKeyPressed(viewerTypes type, const int key);
    void finishPolygonButtonClicked();
    Project on_actionNew_triggered();

    Project on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_panButton_clicked();

    void roundBrushButtonClicked();

    void squareBrushButtonClicked();

    void on_pushButton_14_clicked();

    void on_actionSave_File_triggered();

    void on_saveAndNext_clicked();
    void setInsert();
    void toggleDrawing();
    void toggleErasing();
    void setCurrentLabel(Label *label);
    void setCurrentLabel(LabelButton *button);
    void setCurrentBrushSize(int);
public slots:
    void resetPixmapButtons();


private:
#ifdef WASM_BUILD
    struct MyConnector{
            std::function<void(void)> onActivate;
    };
    void loadRawImage();
    void addConnector(QString text, std::function<void(void)> onActivate);
    MyConnector *openFile;
#endif
    Label *currentLabel;
    Ui::InstaDam *ui;
    newproject *newProject;
    Project currentProject;
    PhotoScene *scene;
    PhotoScene *maskScene;
    QUndoStack *undoStack;
    SelectType currentSelectType;
    SelectItem *currentItem;
    QAction *undoAction;
    QAction *redoAction;
    QByteArray imgData;
    QByteArray fileContent;
    QWidget *blankWidget;
    QWidget *freeSelectWidget;
    QWidget *polygonSelectWidget;
    QGridLayout *controlLayout;
    Ui::blankForm *blankForm;
    Ui::freeSelectForm *freeSelectForm;
    Ui::polygonSelectForm *polygonSelectForm;
    bool drawing = true;
    int lastType = -1;
    bool insertVertex = false;
    int vertex1 = -1;
    int vertex2 = -1;
    int currentBrushSize = 5;
    FreeDrawErase *myErase;
    SelectItem *tempItem;
    SelectItem *mirrorItem;
    int brushMode = Qt::SquareCap;
};




#endif // INSTADAM_H
