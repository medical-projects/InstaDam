/********************************************************************************
** Form generated from reading UI file 'imagelist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGELIST_H
#define UI_IMAGELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageList
{
public:
    QTableWidget *tableWidget;
    QPushButton *cancelButton;
    QPushButton *loadButton;

    void setupUi(QWidget *ImageList)
    {
        if (ImageList->objectName().isEmpty())
            ImageList->setObjectName(QString::fromUtf8("ImageList"));
        ImageList->resize(867, 401);
        tableWidget = new QTableWidget(ImageList);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 10, 751, 341));
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        cancelButton = new QPushButton(ImageList);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(680, 360, 93, 28));
        loadButton = new QPushButton(ImageList);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(570, 360, 93, 28));

        retranslateUi(ImageList);

        QMetaObject::connectSlotsByName(ImageList);
    } // setupUi

    void retranslateUi(QWidget *ImageList)
    {
        ImageList->setWindowTitle(QApplication::translate("ImageList", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ImageList", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ImageList", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ImageList", "Path", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ImageList", "Date_created", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ImageList", "Date_Modified", nullptr));
        cancelButton->setText(QApplication::translate("ImageList", "Cancel", nullptr));
        loadButton->setText(QApplication::translate("ImageList", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageList: public Ui_ImageList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGELIST_H