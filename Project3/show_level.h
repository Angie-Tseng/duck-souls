#ifndef SHOW_LEVEL_H
#define SHOW_LEVEL_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

class ShowLevel: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    static int select_level;

    ShowLevel();
    ShowLevel(int level, QGraphicsItem * parent = NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void set_lock();

signals:
    void clicked();

private:
    int level;
    QGraphicsTextItem * text;
};

#endif // SHOW_LEVEL_H
