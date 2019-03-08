#ifndef FREEDRAWERASE_H
#define FREEDRAWERASE_H

#include "freeDrawSelect.h"
#include <QSet>
#ifdef TEST
class TestSelect;

#endif

typedef QMap<FreeDrawSelect*, FreeMap* > EraseMap;
typedef QMapIterator<FreeDrawSelect*, FreeMap* > EraseMapIterator;

class FreeDrawErase : public FreeDrawSelect
{
public:
    static QString baseInstruction;
    FreeDrawErase(QPointF point, int brushSize, int brushMode, Label *label = nullptr, QGraphicsItem *item = nullptr);
    ~FreeDrawErase() override;

    /*-------------- Implemented fvuntions from SelectItem ---------*/
    bool isInside(QPointF &point) override {UNUSED(point); return false;}
    void moveItem(QPointF &oldPos, QPointF &newPos) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override {UNUSED(painter); UNUSED(option); UNUSED(widget);}
    /*------------- End implemented functions*/

    void drawWithCircle(QPointF &oldPos, QPointF &newPos);
    void drawWithSquare(QPointF &oldPos, QPointF &newPos);

    EraseMap* getMap(){return undoMap;}

protected:
    void rasterizeLine(QPoint &start, QPoint &end);

private:
#ifdef TEST

    friend TestSelect;
#endif
    QVector<int> deleteList;

    EraseMap *undoMap = nullptr;

    //void voidPoint(QPoint &point);
};
#endif // FREEDRAWERASE_H
