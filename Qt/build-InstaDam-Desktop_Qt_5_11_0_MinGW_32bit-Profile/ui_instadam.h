/********************************************************************************
** Form generated from reading UI file 'instadam.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTADAM_H
#define UI_INSTADAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <maskviewer.h>
#include <photoviewer.h>

QT_BEGIN_NAMESPACE

class Ui_InstaDam
{
public:
    QAction *action_Open;
    QAction *action_Save;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionOpen_File;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter_3;
    PhotoViewer *IdmPhotoViewer;
    MaskViewer *IdmMaskViewer;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton_14;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuEdit;

    void setupUi(QMainWindow *InstaDam)
    {
        if (InstaDam->objectName().isEmpty())
            InstaDam->setObjectName(QStringLiteral("InstaDam"));
        InstaDam->setMouseTracking(true);
        InstaDam->setTabletTracking(true);
        InstaDam->setAcceptDrops(true);
        InstaDam->setAutoFillBackground(true);
        InstaDam->setDocumentMode(true);
        InstaDam->setDockNestingEnabled(true);
        InstaDam->setUnifiedTitleAndToolBarOnMac(true);
        action_Open = new QAction(InstaDam);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        action_Save = new QAction(InstaDam);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        actionExit = new QAction(InstaDam);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionUndo = new QAction(InstaDam);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionOpen_File = new QAction(InstaDam);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        centralwidget = new QWidget(InstaDam);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(frame);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(10);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(frame_2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(10);
        scrollArea_2 = new QScrollArea(splitter_2);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setMaximumSize(QSize(150, 16777215));
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 125, 192));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_7);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        splitter_2->addWidget(scrollArea_2);
        frame_3 = new QFrame(splitter_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter_3 = new QSplitter(frame_3);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        IdmPhotoViewer = new PhotoViewer(splitter_3);
        IdmPhotoViewer->setObjectName(QStringLiteral("IdmPhotoViewer"));
        splitter_3->addWidget(IdmPhotoViewer);
        IdmMaskViewer = new MaskViewer(splitter_3);
        IdmMaskViewer->setObjectName(QStringLiteral("IdmMaskViewer"));
        splitter_3->addWidget(IdmMaskViewer);

        horizontalLayout_2->addWidget(splitter_3);

        splitter_2->addWidget(frame_3);

        verticalLayout_4->addWidget(splitter_2);

        splitter->addWidget(frame_2);

        verticalLayout_2->addWidget(splitter);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMaximumSize(QSize(16777215, 70));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_11 = new QPushButton(frame_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        horizontalLayout_4->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(frame_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        horizontalLayout_4->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(frame_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        horizontalLayout_4->addWidget(pushButton_13);

        label = new QLabel(frame_4);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        spinBox = new QSpinBox(frame_4);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_4->addWidget(spinBox);

        pushButton_14 = new QPushButton(frame_4);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        horizontalLayout_4->addWidget(pushButton_14);


        verticalLayout_2->addWidget(frame_4);


        verticalLayout->addWidget(frame);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 240));
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 200));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 978, 198));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 200));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_6 = new QVBoxLayout(tab_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea_3 = new QScrollArea(tab_2);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setMaximumSize(QSize(16777215, 200));
        scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 978, 198));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents_3->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_10);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_6->addWidget(scrollArea_3);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        InstaDam->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(InstaDam);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        InstaDam->setStatusBar(statusbar);
        menubar = new QMenuBar(InstaDam);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 986, 21));
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(true);
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        InstaDam->setMenuBar(menubar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(actionOpen_File);
        menu_File->addAction(action_Save);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);
        menuEdit->addAction(actionUndo);

        retranslateUi(InstaDam);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InstaDam);
    } // setupUi

    void retranslateUi(QMainWindow *InstaDam)
    {
        InstaDam->setWindowTitle(QApplication::translate("InstaDam", "MainWindow", nullptr));
        action_Open->setText(QApplication::translate("InstaDam", "Open Project", nullptr));
        action_Save->setText(QApplication::translate("InstaDam", "Save", nullptr));
        actionExit->setText(QApplication::translate("InstaDam", "Exit", nullptr));
        actionUndo->setText(QApplication::translate("InstaDam", "Undo", nullptr));
        actionOpen_File->setText(QApplication::translate("InstaDam", "Open File", nullptr));
        pushButton_4->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        pushButton_5->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        pushButton_7->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        pushButton_11->setText(QApplication::translate("InstaDam", "Pan", nullptr));
        pushButton_12->setText(QApplication::translate("InstaDam", "Round", nullptr));
        pushButton_13->setText(QApplication::translate("InstaDam", "Square", nullptr));
        label->setText(QApplication::translate("InstaDam", "Brush Size", nullptr));
        pushButton_14->setText(QApplication::translate("InstaDam", "Filter Options", nullptr));
        pushButton->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("InstaDam", "Tab 1", nullptr));
        pushButton_8->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        pushButton_9->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        pushButton_10->setText(QApplication::translate("InstaDam", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("InstaDam", "Tab 2", nullptr));
        menu_File->setTitle(QApplication::translate("InstaDam", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("InstaDam", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InstaDam: public Ui_InstaDam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTADAM_H
