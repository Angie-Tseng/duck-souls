#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>
#include "show_hp.h"
#include "attack_area.h"
#include "minion_image.h"

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Enemy(int get_id);
    ~Enemy();
    int get_id();
    int get_cost();
    void injured(int damage);
    Show_hp * show_hp;
    Attack_area * area;
    Minion_image * image;
    Minion_image * atk_image;

public slots:
    void move();
    void attack();
    void fade();

private:
    static const int SCENE_X = 1600;
    static const int START_Y = 300;
    static const int IMAGE_W = 150;
    static const int IMAGE_H = 200;
    static const int HP_POS_X = 30;
    static const int HP_POS_Y = 10;
    int MOVE;

    int id;
    int cost;
    int hp;
    int atk;
    int speed;
    int range;
    bool minion;
    bool is_fade;

    void initial();
};

#endif // ENEMY_H
