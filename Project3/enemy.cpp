#include "enemy.h"

#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "show_hp.h"
#include "minion.h"
#include "game_manager.h"
#include "card_information.h"
extern GameManager * game_manager;

Enemy::Enemy(int get_id){
    //set enemy
    id = get_id;
    initial();
    setRect(0, 0, IMAGE_W, IMAGE_H);
    setPos(SCENE_X - IMAGE_W, START_Y);
    setOpacity(0);
    MOVE = speed;

    //set image
    image = new Minion_image();
    image->set_image(id, QString("R"));
    image->setPos(x(), y());

    //set attack image
    atk_image = new Minion_image();
    atk_image->set_atk("R");
    atk_image->setOpacity(0);

    //set attack area
    area = new Attack_area(range, atk);
    area->setPos(x() - range + IMAGE_W*0.3, y() + IMAGE_H -2);

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

Enemy::~Enemy(){
    delete show_hp;
    delete area;
    delete image;
    delete atk_image;
}

int Enemy::get_id(){
    return id;
}

int Enemy::get_cost(){
    return cost;
}

void Enemy::injured(int damage){
    //when minion be injured
    hp -= damage;
    show_hp->set_hp(hp);

    //if hp <=0, minion dead
    if(hp <= 0){
        //add souls
        game_manager->add_souls += cost*20;

        delete this;
        qDebug() << "enemy " << id << " destroyed";
    }
}

void Enemy::move(){
    //if is not out of scene and has no minion, move
    if((pos().x() + MOVE >= 0) && !minion){
        setPos(x() - MOVE, y());
        show_hp->setPos(show_hp->x() - MOVE, show_hp->y());
        area->setPos(area->x() - MOVE, area->y());
        image->setPos(image->x() - MOVE, image->y());
        atk_image->setPos(pos());
    }
}

void Enemy::attack(){
    //if minion in attack area, attack
    if (area->enemy_attack() == true){
        minion = true;
        atk_image->setOpacity(0.5);
        is_fade = true;
    }else{
        minion = false;
        atk_image->setOpacity(0);
        is_fade = false;
    }
}

void Enemy::fade(){
    if(is_fade){
        if(atk_image->pos() == pos()-QPointF(range,0))
            atk_image->setPos(pos());
        else
            atk_image->setPos(atk_image->pos()-QPointF(25,0));
    }
}

void Enemy::initial(){
    CardInfo * info = new CardInfo();
    info->set_minion(id);

    cost = info->cost;
    hp = info->hp;
    atk = info->attack;
    speed = info->speed;
    range = info->range;
}

