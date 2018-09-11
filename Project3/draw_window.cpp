#include "game.h"

//this is for showing the draw window

void Game::draw(){
    qDebug() << "[draw window]";

    //clean up the items in the scene
    scene->clear();

    /*** build the select window ***/
    //show souls
    QGraphicsTextItem * souls_text = new QGraphicsTextItem(QString("Souls: ")
                                                           + QString::number(souls));
    souls_text->setDefaultTextColor(Qt::gray);
    souls_text->setFont(BODY_FONT);
    scene->addItem(souls_text);


    //draw button
    Button * draw_button = new Button(QString("DRAW"));
    draw_button->setPos(600, 500);
    scene->addItem(draw_button);
    //connect draw button to this
    connect(draw_button, SIGNAL(clicked()), this, SLOT(draw_clicked()));

    //back button
    Button * back_button = new Button(QString("BACK"));
    back_button->setPos(600,700);
    scene->addItem(back_button);
    //connect back button to the select window
    connect(back_button, SIGNAL(clicked()), this, SLOT(select()));
    /*******************************/
}

void Game::draw_clicked(){
    /*** draw card ***/
    int id = 0;
    QGraphicsTextItem * message;

    //if souls is enough
    if(souls >= 1000){
        //draw card (id 0~15)
        id = rand() % 16;

        //print the new card
        message = new QGraphicsTextItem(QString("You have got card no. ")
                                        + QString::number(id)
                                        + QString(" !!"));
        my_card[id] = 1;
        souls -= 1000;

    }else{
        //else: print souls shortage message
        message = new QGraphicsTextItem("Your souls is not enough!!");

    }

    draw();

    message->setFont(TITLE_FONT);
    message->setDefaultTextColor(Qt::white);
    message->setPos(200, 200);
    scene->addItem(message);

    /*****************/


    //save file
    save();
}
