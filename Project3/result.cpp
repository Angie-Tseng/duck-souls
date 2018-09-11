#include "game.h"
#include <QTextBlockFormat>

//this is for showing the game result

void Game::result(bool is_win, int game_level, int add_souls){
    qDebug() << "[game result]";

    //clear scene
    scene->clear();

    /*** build result window ***/
    //show game result
    QGraphicsTextItem * game_result = new QGraphicsTextItem("");
    if(is_win)
        game_result->setPlainText(" You  Win!!");
    else
        game_result->setPlainText("You  Lose!!");
    game_result->setFont(TITLE_FONT);
    game_result->setPos(500, 50);
    game_result->setDefaultTextColor(Qt::white);
    scene->addItem(game_result);

    //show add souls
    QGraphicsTextItem * souls_text = new QGraphicsTextItem(
                QString("  souls:\t\t\t") + QString::number(souls) +
                QString("\n    + \t\t\t") + QString::number(add_souls) +
                QString("\n_________________________") +
                QString("\n\t\t\t\t") + QString::number(souls+add_souls)
                );

    souls_text->setFont(BODY_FONT);
    souls_text->setDefaultTextColor(Qt::gray);
    souls_text->setPos(500, 300);
    scene->addItem(souls_text);

    souls += add_souls;

    //if win the current level and current level is not the highest level: level complete
    if(is_win && (game_level == current_level) && (current_level < LEVEL_NUMBER)){
        QGraphicsTextItem * level_up_text
                = new QGraphicsTextItem("       Level Complete!!\nNew Magic Card Unlocked");
        level_up_text->setPos(650, 600);
        level_up_text->setFont(COMMENT_FONT);
        level_up_text->setDefaultTextColor(Qt::yellow);
        scene->addItem(level_up_text);

        //give reward: magic card
        switch(current_level){
        case 0:
            my_card[16] = 1; my_card[17] = 1; break;
        case 1:
            my_card[18] = 1; break;
        case 2:
            my_card[19] = 1; break;
        }

        ++current_level;
    }

    //back button
    Button * back_button = new Button(QString("BACK"));
    back_button->setPos(600,700);
    scene->addItem(back_button);
    //connect back button to the main window
    connect(back_button, SIGNAL(clicked()), this, SLOT(select()));
    /***************************/


    //save
    save();
}
