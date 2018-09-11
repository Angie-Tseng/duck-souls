#include "game.h"
#include <QBrush>

//this is for showing the select window

void Game::select(){
    qDebug() << "[select window]";

    //load game
    load();

    //clean up the items in the scene
    scene->clear();

    //set background all black
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    scene->setBackgroundBrush(brush);

    /*** build the select window ***/
    //map button
    Button * map_button = new Button(QString("MAP"));
    map_button->setPos(600, 100);
    scene->addItem(map_button);
    //connect map button to the map window
    connect(map_button, SIGNAL(clicked()), this, SLOT(map()));

    //deck button
    Button * deck_button = new Button(QString("DECK"));
    deck_button->setPos(600, 300);
    scene->addItem(deck_button);
    //connect deck button to the deck manager
    connect(deck_button, SIGNAL(clicked()), this, SLOT(deck_manager_window()));

    //draw button
    Button * draw_button = new Button(QString("DRAW"));
    draw_button->setPos(600, 500);
    scene->addItem(draw_button);
    //connect draw button to the draw window
    connect(draw_button, SIGNAL(clicked()), this, SLOT(draw()));

    //back button
    Button * back_button = new Button(QString("BACK"));
    back_button->setPos(600,700);
    scene->addItem(back_button);
    //connect back button to the main window
    connect(back_button, SIGNAL(clicked()), this, SLOT(main_window()));
    /*******************************/
}
