#ifndef LABELBUTTON_H
#define LABELBUTTON_H

#include <QPushButton>
#include <QSlider>

#include "label.h"

class LabelButton : public QPushButton {
    Q_OBJECT

 public:
    explicit LabelButton(QSharedPointer<Label> label);
    QSlider *slider;
    QSharedPointer<Label> myLabel;
    void clear();
 signals:
    void cclicked(QSharedPointer<Label> label);
    void opacity(QSharedPointer<Label> label, int op);
 public slots:
    void wasClicked();
    void reemitValueChanged(int value);
};

class LabelButtonFilter : public QPushButton {
    Q_OBJECT

 public:
    explicit LabelButtonFilter(QSharedPointer<Label> label);
    QSharedPointer<Label> myLabel;
 signals:
    void cclicked(QSharedPointer<Label> label);
 public slots:
    void wasClicked();
    void clear();
};

#endif  // LABELBUTTON_H
