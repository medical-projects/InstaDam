/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   diagramitem.h
 * Author: friedel
 *
 * Created on February 6, 2019, 9:00 PM
 */

#ifndef SELECTITEM_H
#define SELECTITEM_H

#include <QGraphicsItem>
#include <QWidget>

enum SelectType:int {Generic=50, Rect=51, Ellipse=52,Polygon=53, Free=54};
//enum Side:int {NONE=0, TOP=1, BOTTOM=2, LEFT=4, RIGHT=8};
const int TOP = 0x1;
const int BOTTOM = 0x2;
const int LEFT = 0x4;
const int RIGHT = 0x8;
QT_BEGIN_NAMESPACE
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
class QPointF;
class QGraphicsItemPrivate;
QT_END_NAMESPACE

class SelectItem : public QGraphicsItem
{
    public:
        static qreal vertexSize;
        static QPointF xoffset;
        static QPointF yoffset;

        SelectItem(qreal vertSize = 10., QGraphicsItem *item = nullptr);
        SelectItem(QGraphicsItem *item = nullptr);
        virtual void addPoint(QPointF &point) = 0;
        virtual void moveItem(QPointF &oldPos, QPointF &newPos) = 0;
        virtual void resizeItem(int vertex, QPointF &shift) = 0;
        virtual void clickPoint(QPointF &point) = 0;
        virtual bool isInside(QPointF &point) = 0;
        //virtual void setScene() = 0;
        void sortCorners(QRectF &rect, QPointF &newPoint);
        SelectType getType();
        int type() const override;
        void setActive(){active = true;}
        void setInactive(){active = false;}
        static void setVertexSize(qreal size);
        QGraphicsScene* scene();
        QGraphicsItem* getParentItem();
        bool wasResized(){return resized;}
        bool wasMoved(){return moved;}
        int getActiveVertex(){return activeVertex;}
        void resetState(){
            moved = false;
            resized = false;
        }
        void setActiveVertex(int h, int v = 0){
            //activeH = h;
            //activeV = v;
            activeVertex = 0;
            activeVertex = (h | v);
        }
        void flipH(){
            activeVertex ^= (TOP | BOTTOM);
        }
        void flipV(){
            activeVertex ^= (LEFT | RIGHT);
        }

    protected:
        SelectType selectType;
        QPointF selectedPoint;
        int mytype = Generic;
        bool active = false;
        int activeV = RIGHT;
        int activeH = BOTTOM;
        int activeVertex = (activeV | activeH);
        bool isInsideRect(QRectF &rect, QPointF &point);
        void checkBoundaries(QPointF &shift, QRectF &rect);
        bool resized = false;
        bool moved = false;
        QRectF myRect;
};




#endif /* DIAGRAMITEM_H */
