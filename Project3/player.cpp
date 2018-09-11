#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <iostream>
using namespace std;

#include "tower.h"
#include "minion.h"
#include "show_mana.h"
#include "game_manager.h"

extern GameManager * game_manager;

Player::Player(){
    //initialize player
    setFlag(QGraphicsItem::ItemIsFocusable);

    //connect mana
    connect(game_manager->player_timer, SIGNAL(timeout()), this, SLOT(add_mana()));

    //connect anounce
    QTimer * anounce_timer = new QTimer();
    connect(anounce_timer, SIGNAL(timeout()), this, SLOT(fade()));
    anounce_timer->start(100);

    //initialize show_mana
    show_mana = new Show_mana();

    //initialize anounce
    anounce = new Anounce();

    //initialize game timer
    game_time = new Game_time();

    //initialize tower
    tower = new Tower();
}

bool Player::send_minion(int id){
    //if wrong key pressed: do nothing
    if(id == -1) return false;

    //generate minion according to id
    Minion * minion = new Minion(id);

    //if mana is not enough: do nothing
    if(show_mana->get_mana() < minion->get_cost()){
        anounce->set_anounce("MANA SHORTAGE!!");
        qDebug() << "Mana shortage.";
        delete minion;
        return false;
    }

    //else: send minion
    cout << "Send minion " << id << endl;
    scene()->addItem(minion);
    scene()->addItem(minion->show_hp);
    scene()->addItem(minion->image);
    scene()->addItem(minion->area);
    scene()->addItem(minion->atk_image);

    //mana decrease
    show_mana->decrease(minion->get_cost());
    return true;
}

void Player::keyPressEvent(QKeyEvent *event){
    int id = 0;

    switch(event->key()){
        case Qt::Key_1: id = 1; break;
        case Qt::Key_2: id = 2; break;
        case Qt::Key_3: id = 3; break;
        case Qt::Key_4: id = 4; break;
    }

    //if wrong key pressed: do nothing
    if(id == 0) return;

    //generate minion according to id
    Minion * minion = new Minion(id);

    //if mana is not enough: do nothing
    if(show_mana->get_mana() < minion->get_cost()){
        qDebug() << "Mana shortage.";
        delete minion;
        return;
    }

    //else: send minion
    cout << "Send minion " << id << endl;
    scene()->addItem(minion);
    scene()->addItem(minion->show_hp);
    scene()->addItem(minion->image);
    scene()->addItem(minion->area);
    scene()->addItem(minion->atk_image);

    //mana decrease
    show_mana->decrease(minion->get_cost());
}

void Player::add_mana(){
    //add mana per seconds
    show_mana->increase();

    //countdown
    if(game_time->countdown == 0){
        if(game_manager->player->tower->hp > game_manager->ai->tower_ai->hp)
            game_manager->game_over("You  Win!!");
        else if(game_manager->player->tower->hp < game_manager->ai->tower_ai->hp)
            game_manager->game_over("You Lose!!");
        else
            game_manager->game_over("Tie Game!!");
    }else
        game_time->decrease();

}

void Player::fade(){
    if(anounce->opacity()!=0){
        anounce->setOpacity(anounce->opacity()-0.1);
        anounce->setPos(anounce->pos()-QPointF(0,3));
    }
}
