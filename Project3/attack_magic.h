#ifndef ATTACK_MAGIC_H
#define ATTACK_MAGIC_H

#include <QGraphicsRectItem>

class AttackMagic: public QGraphicsRectItem{
public:
    AttackMagic(int id, int x, int range, QGraphicsItem * parent = NULL);
    void attack_magic(int attack);
};

#endif // ATTACK_MAGIC_H
