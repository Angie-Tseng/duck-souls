#include "game.h"
#include "show_level.h"

//this is for showing the map (level) select window

void Game::map(){
    qDebug() << "[story window]";

    //clear scene
    scene->clear();

    /*** build the map window ***/
    //generate title
    QGraphicsTextItem * level_text = new QGraphicsTextItem("Select Level:");
    level_text->setPos(0, 50);
    level_text->setDefaultTextColor(Qt::gray);
    level_text->setFont(BODY_FONT);
    scene->addItem(level_text);

    //generate level button
    for(int i=0; i<LEVEL_NUMBER; ++i){
        ShowLevel * show_level = new ShowLevel(i);
        show_level->setPos(150 + 500*i, 200);

        //if is higher than current level: set locked level button
        if(i > current_level)
            show_level->set_lock();

        scene->addItem(show_level);

        //connect level button with clicked()
        connect(show_level, SIGNAL(clicked()), this, SLOT(level_clicked()));
    }

    //back button
    Button * back_button = new Button(QString("BACK"));
    back_button->setPos(600,700);
    scene->addItem(back_button);
    //connect back button to the select window
    connect(back_button, SIGNAL(clicked()), this, SLOT(select()));
    /****************************/
}



void Game::level_clicked(){
    int level = ShowLevel().select_level;

    //if the selected level is too high: do nothing
    if(level > current_level)
        return;

    //else: set AI to this level
    play(level);
}
