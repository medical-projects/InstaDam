#include <QtWidgets>
#include <iostream>
using namespace std;

#include "photoScene.h"
#include "selectItem.h"

PhotoScene::PhotoScene(viewerTypes type, QObject *parent)
    : QGraphicsScene(parent), currentItems(), labelmap()
{
    myViewerType = type;
    movingItem = nullptr;
    mousePressed = false;
}

// NEED TO MAKE SURE DRAWING DOES NOT GO BEYOND BOUNDARY
void PhotoScene::inactiveAll(){
    for(std::list<SelectItem*>::const_iterator iterator = currentItems.begin(), end = currentItems.end(); iterator != end; ++iterator) {
        (*iterator)->setInactive();
    }

}
void PhotoScene::addItem(QGraphicsItem* item){
    QGraphicsScene::addItem(item);

}
void PhotoScene::addLabelItem(QGraphicsItem* item){
    QGraphicsScene::addItem(item);


}
void PhotoScene::addItem(SelectItem* item){
    currentItems.push_front(item);
    QGraphicsScene::addItem(item);
    labelItems.append(item);
}

void PhotoScene::clearItems()
{
    qInfo("The number of labels is %d",labelItems.length());
    for (int i = 0; i < labelItems.length(); i++)
    {
        this->removeItem(labelItems[i]);
        //delete labelItems[i];
    }
    labelItems.clear();
    currentItems.clear();
    labelmap.clear();

}

void PhotoScene::keyPressEvent(QKeyEvent *event){
    emit keyPressed(myViewerType, event->key());
    QGraphicsScene::keyPressEvent(event);
}

void PhotoScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton || event->button() == Qt::RightButton){
        mousePressed = true;
        QPointF mousePos(event->scenePos().x(),
                         event->scenePos().y());
        SelectItem *item = itemAt(mousePos);

        oldPos = mousePos;
        newPos = mousePos;
        if(item && item->type() != 7){
            emit pointClicked(myViewerType, item, mousePos, event->button());
        }
        else{
            emit pointClicked(myViewerType, nullptr, mousePos, event->button());
        }

    }
    QGraphicsScene::mousePressEvent(event);
}

void PhotoScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event){
    if(mousePressed){
        //cout << "   L" << endl;
        QPointF mousePos(event->scenePos().x(),
                     event->scenePos().y());
        emit mouseMoved(newPos, mousePos);
        newPos = mousePos;
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void PhotoScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton || event->button() == Qt::RightButton){
        //cout << "   LEFT" << endl;
        mousePressed = false;
        //cout << oldPos.x() << "," << oldPos.y() << "  " << newPos.x() << "," << newPos.y() << endl;
        emit mouseReleased(myViewerType, oldPos, newPos, event->button());
    }
    QGraphicsScene::mouseReleaseEvent(event);
}

SelectItem* PhotoScene::itemAt(QPointF point){
    //cout << "ITEMAT " << currentItems.size() << endl;
    for(std::list<SelectItem*>::const_iterator iterator = currentItems.begin(), end = currentItems.end(); iterator != end; ++iterator) {
        //cout <<"Q" << endl;
        if((*iterator)->isVisible() && (*iterator)->isInside(point)){
            //cout << "Z" << endl;
            return (*iterator);
        }
    }
    //cout << "W" << endl;
    return nullptr;

}

SelectItem* PhotoScene::itemAt(QPointF point, std::string label){

    for(std::list<SelectItem*>::const_iterator iterator = labelmap[label].begin(), end = labelmap[label].end(); iterator != end; ++iterator) {
        if((*iterator)->isInside(point)){
            return (*iterator);
        }
    }
    return nullptr;
}

void PhotoScene::addLabel(std::string label){
    std::map<string, std::list<SelectItem*> >::iterator it = labelmap.find(label);
    if (it == labelmap.end()){
        std::list<SelectItem*> newlist;
        labelmap[label] = newlist;
    }
}
void PhotoScene::setCurrentLabel(std::string label){
    currentLabel = label;
}

void PhotoScene::addLabelItem(SelectItem* item, std::string label){
    currentItems.push_front(item);
    labelmap[label].push_front(item);
}

