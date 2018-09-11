#include "game_manager.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QFont>
#include <cstdlib>
#include <ctime>
#include <QTimer>
#include <iostream>
using namespace std;

#include "player.h"
#include "deck.h"
#include "button.h"
#include "game.h"

extern Game * game;

//for game window initial
GameManager::GameManager(int ai_level, int initial_pool[], int initial_magic){

    //initialize timer
    player_timer = new QTimer();
    ai_attack_timer = new QTimer();
    move_timer = new QTimer();
    attack_timer = new QTimer();
    fade_timer = new QTimer();

    player_timer->start(1000);
    move_timer->start(100);
    attack_timer->start(500);
    fade_timer->start(100);
    is_pause = false;

    //initialize add_souls
    add_souls = 0;


    //initialize pool
    for(int i=0; i<POOL_NUMBER; ++i)
        pool[i] = initial_pool[i];

    //initialize magic card
    magic_id = initial_magic;


    //set ai level
    game_level = ai_level;
    set_ai_timer();

    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, WINDOW_X, WINDOW_Y);
    QPixmap background(QString(":/image/image/level") + QString::number(game_level) + QString(".png"));
    scene->setBackgroundBrush(QBrush(background));

    //set game view
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_X, WINDOW_Y);


    //connect countdown
    counter = 10;
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(countdown()));
    timer->start(1000);

    //prepare game
    pre_game();
}


//for game result
void GameManager::game_over(bool is_win){
    qDebug() << "win? " << is_win;

    //disable all items
    for(int i=0; i<scene->items().size(); ++i){
        scene->items()[i]->setEnabled(false);
    }

    delete player;
    delete ai;

    //show main window
    game->show();

    //show result
    game->result(is_win, game_level, add_souls);

    //hide this
    this->hide();
}


//for drawing cards
void GameManager::draw(){
    //draw randomly
    int r = -1;
    r= rand()%POOL_SIZE;

    while(pool[r] == -1)
        r= rand()%POOL_SIZE;

    cout << r << endl;
    qDebug() << "draw " <<  pool[r];
    Deck * new_deck = new Deck(pool[r], DECK_NUMBER-1);
    deck.push_back(new_deck);
    scene->addItem(deck.back());
    scene->addItem(deck.back()->image);

    //align left
    align();
}

//for countdown
void GameManager::pre_game(){
    qDebug() << "prepare";
    scene->clear();
    //pop up semi transparent panel
    draw_panel(0, 0, WINDOW_X, WINDOW_Y, Qt::black, 0.85);

    //pop up countdown
    show_count = new QGraphicsTextItem("");
    show_count->setDefaultTextColor(Qt::white);
    show_count->setFont(QFont("Times", 72, QFont::Bold));
    show_count->setPos(650, 300);
    scene->addItem(show_count);

    counter = 3;
}

void GameManager::countdown(){
    if(counter < 0){
        counter = 3;
        start();
    }else if(counter <=3){
        show_count->setPlainText(QString("     ")+QString::number(counter));
        counter--;
    }
}


//for game start
void GameManager::start(){
    counter = 100;
    scene->clear();
    qDebug() << "clear";

    //add player
    player = new Player();
    scene->addItem(player);
    scene->addItem(player->show_mana);
    scene->addItem(player->anounce);
    scene->addItem(player->game_time);
    //show player's tower
    scene->addItem(player->tower);
    scene->addItem(player->tower->image);
    scene->addItem(player->tower->area);
    scene->addItem(player->tower->show_hp);
    scene->addItem(player->tower->atk_image);
    //focus on player
    player->setFocus();
    qDebug() << "build player";

    //create deck
    deck.clear();

    int card_counter = 0;

    for(int i=0; i<DECK_NUMBER; ++i){
        if(pool[i] == -1) continue;

        ++card_counter;
        Deck * new_deck = new Deck(pool[i], i);
        deck.push_back(new_deck);

        scene->addItem(deck.at(i));
        scene->addItem(deck.at(i)->image);
    }

    //if not full: draw until full
    for(card_counter; card_counter < DECK_NUMBER; ++card_counter){
        draw();
    }

    //align
    align();
    qDebug() << "build deck";


    //add AI
    ai = new Ai(game_level);
    scene->addItem(ai);
    //scene->addItem(ai->show_mana);
    //show AI's tower
    scene->addItem(ai->tower_ai);
    scene->addItem(ai->tower_ai->image);
    scene->addItem(ai->tower_ai->area);
    scene->addItem(ai->tower_ai->show_hp);
    scene->addItem(ai->tower_ai->atk_image);
    qDebug() << "build AI";

    //pause button
    pause_button = new Button("PAUSE");
    pause_button->setRect(0, 0, 120, 50);
    pause_button->text->setPos(10, 10);
    pause_button->text->setFont(QFont("Engravers MT",16));
    connect(pause_button,SIGNAL(clicked()),this,SLOT(pause()));
    pause_button->setPos(100, 750);
    scene->addItem(pause_button);


    //magic card
    magic = new Magic(magic_id);
    scene->addItem(magic);
}

//for game pause
void GameManager::pause(){
    qDebug() << "pause";
    if(is_pause){
        player_timer->start(1000);
        move_timer->start(100);
        attack_timer->start(500);
        fade_timer->start(100);
        magic->timer->start(1000);
        is_pause = false;
        pause_button->text->setPlainText("PAUSE");
    }else{
        player_timer->stop();
        move_timer->stop();
        attack_timer->stop();
        fade_timer->stop();
        magic->timer->stop();
        is_pause = true;
        pause_button->text->setPlainText("PLAY ON");
    }
}

void GameManager::align()
{
    //align left
    for(int i=0; i<deck.size(); ++i){
        Deck * buffer = deck.at(i);
        buffer->set_num(i);
        buffer->setPos(350+i*(IMAGE_W+50), 600);
        buffer->image->setPos(buffer->pos());
        deck.at(i) = buffer;
    }
}

void GameManager::set_ai_timer(){
    switch(game_level){
    case 0: ai_attack_timer->start(7000); break;
    case 1: ai_attack_timer->start(5000); break;
    case 2: ai_attack_timer->start(3000); break;
    }
}

void GameManager::draw_panel(int x, int y, int w, int h, QColor color, double opcacity){
    QGraphicsRectItem * panel = new QGraphicsRectItem(x, y, w, h);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opcacity);
    scene->addItem(panel);
}
