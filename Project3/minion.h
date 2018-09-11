#ifndef MINION_H
#define MINION_H

#include <QObject>
#include <QGraphicsRectItem>
#include "show_hp.h"
#include "minion_image.h"
#include "attack_area.h"

class Minion: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Minion(int get_id);
    ~Minion();
    int get_hp();
    int get_cost();
    void injured(int damage);
    Show_hp * show_hp;
    Minion_image * image;
    Minion_image * atk_image;
    Attack_area * area;

public slots:
    void attack();
    void move();
    void fade();

private:
    static const int SCENE_X = 1600;
    static const int START_Y = 300;
    static const int IMAGE_W = 150;
    static const int IMAGE_H = 200;
    static const int HP_POS_X = 70;
    static const int HP_POS_Y = 10;
    int MOVE;

    int id;
    int cost;
    int hp;
    int atk;
    int speed;
    int range;
    bool enemy;
    bool is_fade;

    void initial();
};

#endif // MINION_H
