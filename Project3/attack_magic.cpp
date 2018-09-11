#include "attack_magic.h"
#include "enemy.h"
#include <QBrush>
#include <QPen>

AttackMagic::AttackMagic(int id, int x, int range, QGraphicsItem * parent): QGraphicsRectItem(parent){
    setRect(0, 0, range, 550);
    setPos(x - range/2, 0);
    setOpacity(0.3);
    setPen(QPen(Qt::NoPen));

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if(id <= 17)
        brush.setColor(Qt::darkBlue);
    else
        brush.setColor(Qt::darkRed);

    setBrush(brush);
}

void AttackMagic::attack_magic(int attack){
    QList <QGraphicsItem *> in_area = collidingItems();
    //find the closest
    for(int i=0; i<in_area.size(); ++i){
        Enemy * enemy = dynamic_cast <Enemy *> (in_area[i]);
        if(enemy){
            enemy->injured(attack);
        }
    }
}
