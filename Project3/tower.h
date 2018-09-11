#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QGraphicsRectItem>
#include "show_hp.h"
#include "minion_image.h"
#include "attack_area.h"

class Tower: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Tower();
    ~Tower();
    void injured(int damage);
    Show_hp * show_hp;
    Minion_image * image;
    Minion_image * atk_image;
    Attack_area * area;
    int hp;

public slots:
    void attack();
    void fade();

private:
    static const int START_Y = 300;
    static const int IMAGE_W = 150;
    static const int IMAGE_H = 200;
    static const int HP_POS_X = 20;
    static const int HP_POS_Y = 25;

    int atk;
    int range;
    bool is_fade;
};

#endif // TOWER_H
