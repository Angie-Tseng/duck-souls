#include "game.h"
#include <QPixmap>

//this is for showing the main window

void Game::main_window(){
    qDebug() << "[main window]";

    //clean up the items in the scene
    scene->clear();

    /*** build the main window ***/
    //set background
    QPixmap background(":/image/image/title.png");
    scene->setBackgroundBrush(QBrush(background));


    //new game button
    Button * new_button = new Button(QString("NEW GAME"));
    new_button->setPos(600,500);
    scene->addItem(new_button);
    //connect new button to new game
    connect(new_button, SIGNAL(clicked()), this, SLOT(new_game()));

    //start button
    Button * start_button = new Button(QString("LOAD GAME"));
    start_button->setPos(600,700);
    scene->addItem(start_button);
    //connect start button to the select window
    connect(start_button, SIGNAL(clicked()), this, SLOT(select()));
    /******************************/
}
