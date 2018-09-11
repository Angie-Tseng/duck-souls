#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Button(QString text, QGraphicsItem * parent = NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    QGraphicsTextItem * text;

signals:
    void clicked();

private:

};

#endif // BUTTON_H
