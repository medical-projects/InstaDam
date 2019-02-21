#ifndef ELLIPSE_SELECT_H
#define ELLIPSE_SELECT_H

#include "selectItem.h"

class EllipseSelect : public QGraphicsEllipseItem, public SelectItem
{
    public:
        EllipseSelect(QPointF point, QGraphicsItem *item = nullptr);

        void addPoint(QPointF &point) override;
        void moveItem(QPointF &oldPos, QPointF &newPos) override;
        void resizeItem(int vertex, QPointF &shift) override;
        void clickPoint(QPointF &point) override;
        QRectF boundingRect() const override;
        bool isInside(QPointF &point) override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
        QGraphicsScene* scene();

    private:
        void calcCorners();
        QRectF tl, bl, tr, br;
};
#endif // ELLIPSE_SELECT_H