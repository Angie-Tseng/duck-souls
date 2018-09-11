#include "minion.h"

#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QList>
#include <QPointF>
#include "show_hp.h"
#include "enemy.h"
#include "tower.h"
#include "card_information.h"

#include <QDebug>

#include "game_manager.h"
extern GameManager * game_manager;

Minion::Minion(int get_id){
    //set minion
    setPos(0, START_Y);
    id = get_id;
    initial();
    MOVE = speed;
    setRect(0, 0, IMAGE_W, IMAGE_H);
    setOpacity(0);

    //set image
    image = new Minion_image();
    image->set_image(id, QString("L"));
    image->setPos(0, START_Y);

    //set attack image
    atk_image = new Minion_image();
    atk_image->set_atk("L");
    atk_image->setOpacity(0);

    //set attack area
    area = new Attack_area(range, atk);
    area->setPos(IMAGE_W*0.7, y() + 1);

    //connect move
    connect(game_manager->move_timer, SIGNAL(timeout()), this, SLOT(move()));

    //connect attack
    connect(game_manager->attack_timer, SIGNAL(timeout()), this, SLOT(attack()));

    //connect fade
    connect(game_manager->fade_timer, SIGNAL(timeout()), this, SLOT(fade()));

    //initialize show_hp
    show_hp = new Show_hp();
    show_hp->set_hp(hp);
    show_hp->setPos(x()+HP_POS_X, y()-HP_POS_Y);
}

Minion::~Minion(){
    delete show_hp;
    delete area;
    delete image;
    delete atk_image;
}

int Minion::get_cost(){
    return cost;
}

void Minion::injured(int damage){
    //when minion be injured
    hp -= damage;
    show_hp->set_hp(hp);

    //if hp <=0, minion dead
    if(hp <= 0){
        delete this;
        qDebug() << "minion " << id << " destroyed";
    }
}

void Minion::attack(){
    //if enemy in attack area, attack
    if (area->minion_attack() == true){
        enemy = true;
        atk_image->setOpacity(0.5);
        is_fade = true;
    }else{
        enemy = false;
        atk_image->setOpacity(0);
        is_fade = false;
    }
}

void Minion::move(){
    //if is not out of scene and has no enemy, move
    if((pos().x() + MOVE <= SCENE_X - IMAGE_W) && !enemy){
        setPos(x() + MOVE, y());
        image->setPos(image->x() + MOVE, image->y());
        show_hp->setPos(show_hp->x() + MOVE, show_hp->y());
        area->setPos(area->x() + MOVE, area->y());
        atk_image->setPos(pos());
    }
}

void Minion::fade(){
    if(is_fade){
        if(atk_image->pos() == pos()+QPointF(range,0))
            atk_image->setPos(pos());
        else
            atk_image->setPos(atk_image->pos()+QPointF(25,0));
    }
}

void Minion::initial(){
    CardInfo * info = new CardInfo();
    info->set_minion(id);

    cost = info->cost;
    hp = info->hp;
    atk = info->attack;
    speed = info->speed;
    range = info->range;
}

