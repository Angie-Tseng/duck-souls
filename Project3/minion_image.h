#ifndef MINION_IMAGE_H
#define MINION_IMAGE_H

#include <QGraphicsPixmapItem>

class Minion_image: public QGraphicsPixmapItem{
public:
    Minion_image(QGraphicsPixmapItem * parent = 0);
    void set_image(int id, QString from);
    void set_image(bool is_player);
    void set_deck(int id);
    void set_bk();
    void set_atk(QString from);
};

#endif // MINION_IMAGE_H
