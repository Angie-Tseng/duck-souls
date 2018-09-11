#include "game.h"

//constructor: initial the window

Game::Game(){

    //set font
    TITLE_FONT = QFont("Times", 80);
    BODY_FONT = QFont("Times", 36);
    COMMENT_FONT = QFont("Times", 20);

    //create initial scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, WINDOW_X, WINDOW_Y);

    //set view
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_X, WINDOW_Y);

    //set main window
    main_window();
}

//destructor: close the window
Game::~Game(){
}
