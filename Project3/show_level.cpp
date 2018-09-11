#include "show_level.h"
#include <QGraphicsTextItem>
#include <QDebug>
#include <QBrush>
#include <QFont>

ShowLevel::ShowLevel(){
}

ShowLevel::ShowLevel(int level, QGraphicsItem * parent): QGraphicsRectItem(parent){
    setRect(0, 0, 300, 300);
    this->level = level;

    text = new QGraphicsTextItem(QString::number(level), this);
    text->setFont(QFont("Times", 80));
    text->setPos(100, 50);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    setAcceptHoverEvents(true);
}

void ShowLevel::mousePressEvent(QGraphicsSceneMouseEvent *event){
    select_level = level;
    //when clicked: send the "clicked" signal.
    emit clicked();
}

void ShowLevel::set_lock(){
    //if current level is too low: set the level button dark gray
    QGraphicsRectItem * panel = new QGraphicsRectItem(this);
    panel->setRect(0, 0, 300, 300);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    panel->setBrush(brush);
    panel->setOpacity(0.3);
    setAcceptHoverEvents(false);
}



void ShowLevel::hoverEnterEvent(QGraphicsSceneHoverEvent *event){

    //for mouse on the button: button color turn light
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    text->setDefaultTextColor(Qt::black);
}

void ShowLevel::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    //for mouse leave the button: restore the color
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    text->setDefaultTextColor(Qt::white);
}
