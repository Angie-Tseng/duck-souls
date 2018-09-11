#include "tower.h"

#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "show_hp.h"
#include "enemy.h"
#include "game_manager.h"

extern GameManager * game_manager;

Tower::Tower(){
    //set tower
    setPos(0, START_Y);
    hp = 3000;
    atk = 10;
    range = 500;
    setRect(0, 0, IMAGE_W, IMAGE_H);
    setOpacity(0);

    //set image
    image = new Minion_image();
    image->set_image(true);
    image->setPos(0, START_Y);

    //set attack image
    atk_image = new Minion_image();
    atk_image->set_atk("L");
    atk_image->setOpacity(0);
    atk_image->setPos(0, START_Y);

    //set attack area
    area = new Attack_area(range, atk);
    area->setPos(x() + IMAGE_W, y() + IMAGE_H/2);

    //connect attack
    connect(game_manager->attack_timer, SIGNAL(timeout()), this, SLOT(attack()));

    //connect fade
    connect(game_manager->fade_timer, SIGNAL(timeout()), this, SLOT(fade()));

    //initialize show_hp
    show_hp = new Show_hp();
    show_hp->set_hp(hp);
    show_hp->setPos(x()+HP_POS_X, y()-HP_POS_Y);
}

Tower::~Tower(){
    delete show_hp;
    delete area;
    delete image;
}

void Tower::injured(int damage){
    hp -= damage;
    show_hp->set_hp(hp);

    //if hp <=0, minion dead
    if(hp <= 0){
        delete this;
        qDebug() << "Tower destroyed";

        game_manager->game_over(false);
    }
}

void Tower::attack(){
    //if enemy in attack area, attack
    if (area->minion_attack() == true){
        atk_image->setOpacity(0.3);
        is_fade = true;
    }else{
        atk_image->setOpacity(0);
        is_fade = false;
    }
}

void Tower::fade(){
    if(is_fade){
        if(atk_image->x() == 500)
            atk_image->setPos(pos());
        else{
            atk_image->setPos(atk_image->x() + 25, atk_image->y());
        }
    }
}
