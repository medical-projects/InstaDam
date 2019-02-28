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
    void clearLayout(QLayout * layout) ;


private slots:
    void on_actionOpen_File_triggered();
    void on_rectangleSelectButton_clicked();
    void on_ellipseSelectButton_clicked();
    void on_polygonSelectButton_clicked();
    void on_freeSelectButton_clicked();
    void processMouseMoved(QPointF fromPos, QPointF toPos);
    void processPointClicked(SelectItem *item, QPointF pos);
    void processLeftMouseReleased(QPointF oldPos, QPointF newPos);
    void processKeyPressed(const int key);

    Project on_actionNew_triggered();

    Project on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_panButton_clicked();

    void on_roundBrushButton_clicked();

    void on_squareBrushButton_clicked();

    void on_pushButton_14_clicked();

    void on_actionSave_File_triggered();

    void on_saveAndNext_clicked();

public slots:
    void resetPixmapButtons();


private:
    Ui::InstaDam *ui;
    newproject *newProject;
    Project currentProject;
    PhotoScene *scene;
    QUndoStack *undoStack;
    SelectType currentSelectType;
    SelectItem *currentItem;
    QAction *undoAction;
    QAction *redoAction;
    QWidget *blankWidget;
    QWidget *freeSelectWidget;
    QWidget *polygonSelectWidget;
    QGridLayout *controlLayout;
};




#endif // INSTADAM_H
