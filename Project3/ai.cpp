#include "ai.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "enemy.h"
#include "show_mana.h"
#include "tower_ai.h"
#include "game_manager.h"

extern GameManager * game_manager;

Ai::Ai(int level){
    //initialize AI
    setFlag(QGraphicsItem::ItemIsFocusable);

    //connect mana
    connect(game_manager->player_timer, SIGNAL(timeout()), this, SLOT(add_mana()));

    //connect aquire
    connect(game_manager->ai_attack_timer, SIGNAL(timeout()), this,SLOT(aquire()));

    //initialize show_mana
    show_mana = new Show_mana();
    show_mana->setPos(1480, 0);

    //initialize tower
    tower_ai = new Tower_ai();
    tower_ai->setPos(1500, 200);

    //set pool
    set_pool(level);
}

void Ai::aquire(){
    int id = -1;
    id = (rand() % 8) + pool;
    qDebug() << id;

    if(id == -1) return;

    //generate enemy according to id
    Enemy * enemy = new Enemy(id);

    //else: send enemy
    cout << "Send enemy " << id << endl;
    scene()->addItem(enemy);
    scene()->addItem(enemy->image);
    scene()->addItem(enemy->show_hp);
    scene()->addItem(enemy->area);
    scene()->addItem(enemy->atk_image);

    //mana decrease
    show_mana->decrease(enemy->get_cost());
}

void Ai::set_pool(int level){
    switch(level){
    case 0: pool = 0; break;
    case 1: pool = 4; break;
    case 2: pool = 8; break;
    }
    qDebug() << "AI LEVEL: " << level << " | " << pool;
}

void Ai::add_mana(){
    //add mana per seconds
    show_mana->increase();
}
