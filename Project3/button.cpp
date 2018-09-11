#include "button.h"
#include <QBrush>
#include <QFont>
#include <QDebug>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    //draw a rect
    setRect(0,0,400,100);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    //draw a text
    text = new QGraphicsTextItem(name,this);
    text->setDefaultTextColor(Qt::white);
    text->setFont(QFont("Times",24));
    text->setPos(
                rect().width()/2 - text->boundingRect().width()/2,
                rect().height()/2 - text->boundingRect().height()/2
                );

    //allow hover action
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //when clicked: send the "clicked" signal.
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){

    //for mouse on the button: button color turn light
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    text->setDefaultTextColor(Qt::black);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    //for mouse leave the button: restore the color
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    text->setDefaultTextColor(Qt::white);
}
