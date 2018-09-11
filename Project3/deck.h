#ifndef DECK_H
#define DECK_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "minion_image.h"

class Deck: public QGraphicsRectItem{
public:
    Deck();
    Deck(int get_id, int number);
    ~Deck();

    Minion_image * image;

    void set_id(int get_id);
    void set_num(int number);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

    static int deck_counter;

private:
    int id;
    int num;
    const static int IMAGE_W = 150;
    const static int IMAGE_H = 200;

    QGraphicsRectItem * info;
};

#endif // DECK_H
