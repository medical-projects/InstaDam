/********************************************************************************
** Form generated from reading UI file 'polygonSelect.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLYGONSELECT_H
#define UI_POLYGONSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_polygonSelectForm
{
public:
    QGridLayout *gridLayout;
    QPushButton *insertPointButton;
    QPushButton *finishPolygonButton;
    QPlainTextEdit *polygonMessageBox;

    void setupUi(QWidget *polygonSelectForm)
    {
        if (polygonSelectForm->objectName().isEmpty())
            polygonSelectForm->setObjectName(QStringLiteral("polygonSelectForm"));
        polygonSelectForm->resize(1413, 158);
        gridLayout = new QGridLayout(polygonSelectForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        insertPointButton = new QPushButton(polygonSelectForm);
        insertPointButton->setObjectName(QStringLiteral("insertPointButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(insertPointButton->sizePolicy().hasHeightForWidth());
        insertPointButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(insertPointButton, 1, 0, 1, 1);

        finishPolygonButton = new QPushButton(polygonSelectForm);
        finishPolygonButton->setObjectName(QStringLiteral("finishPolygonButton"));
        sizePolicy.setHeightForWidth(finishPolygonButton->sizePolicy().hasHeightForWidth());
        finishPolygonButton->setSizePolicy(sizePolicy);
        finishPolygonButton->setMinimumSize(QSize(252, 36));

        gridLayout->addWidget(finishPolygonButton, 0, 0, 1, 1);

        polygonMessageBox = new QPlainTextEdit(polygonSelectForm);
        polygonMessageBox->setObjectName(QStringLiteral("polygonMessageBox"));
        polygonMessageBox->setUndoRedoEnabled(false);
        polygonMessageBox->setReadOnly(true);

        gridLayout->addWidget(polygonMessageBox, 0, 1, 2, 1);


        retranslateUi(polygonSelectForm);

        QMetaObject::connectSlotsByName(polygonSelectForm);
    } // setupUi

    void retranslateUi(QWidget *polygonSelectForm)
    {
        polygonSelectForm->setWindowTitle(QApplication::translate("polygonSelectForm", "Form", nullptr));
        insertPointButton->setText(QApplication::translate("polygonSelectForm", "Insert Point Between", nullptr));
        finishPolygonButton->setText(QApplication::translate("polygonSelectForm", "Finish Polygon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class polygonSelectForm: public Ui_polygonSelectForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLYGONSELECT_H
