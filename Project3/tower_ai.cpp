#include "tower_ai.h"

#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "show_hp.h"
#include "minion.h"
#include "game_manager.h"

extern GameManager * game_manager;

Tower_ai::Tower_ai(){
    //set Tower_ai
    setPos(0, START_Y);
    hp = 3000;
    atk = 10;
    range = 500;
    setRect(0, 0, IMAGE_W, IMAGE_H);
    setPos(SCENE_X - IMAGE_W, START_Y);
    setOpacity(0);

    //set image
    image = new Minion_image();
    image->set_image(false);
    image->setPos(x(), y());

    //set attack image
    atk_image = new Minion_image();
    atk_image->set_atk("R");
    atk_image->setOpacity(0);
    atk_image->setPos(pos());

    //set attack area
    area = new Attack_area(range, atk);
    area->setPos(x() - range, y() + IMAGE_H / 2);

    //connect attack
    connect(game_manager->attack_timer, SIGNAL(timeout()), this, SLOT(attack()));

    //connect fade
    connect(game_manager->fade_timer, SIGNAL(timeout()), this, SLOT(fade()));

    //initialize show_hp
    show_hp = new Show_hp();
    show_hp->set_hp(hp);
    show_hp->setPos(x()+HP_POS_X, y()-HP_POS_Y);
}

Tower_ai::~Tower_ai(){
    delete show_hp;
    delete area;
    delete image;
}

void Tower_ai::injured(int damage){
    hp -= damage;
    show_hp->set_hp(hp);

    //if hp <=0, minion dead
    if(hp <= 0){
        delete this;
        qDebug() << "Tower_ai destroyed";
        game_manager->game_over(true);
    }
}

void Tower_ai::attack(){
    //if minion in attack area, attack
    if (area->enemy_attack() == true){
        atk_image->setOpacity(0.5);
        is_fade = true;
    }else{
        atk_image->setOpacity(0);
        is_fade = false;
    }
}

void Tower_ai::fade(){
    if(is_fade){
        if(atk_image->pos() == pos()-QPointF(range,0))
            atk_image->setPos(pos());
        else
            atk_image->setPos(atk_image->pos()-QPointF(25,0));
    }
}
