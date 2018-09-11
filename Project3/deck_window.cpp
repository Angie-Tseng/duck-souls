#include "game.h"
#include "show_card.h"

//this is for showing the deck manager

void Game::deck_manager_window(){
    qDebug() << "[deck manager]";

    //clear scene
    scene->clear();

    /*** set up the deck manager window ***/
    //show deck manager
    deck_manager = new DeckManager(my_card, my_deck, my_magic);
    scene->addItem(deck_manager);

    //decks title
    QGraphicsTextItem * deck_text = new QGraphicsTextItem("deck:");
    deck_text->setFont(BODY_FONT);
    deck_text->setPos(50, 450);
    deck_text->setDefaultTextColor(Qt::gray);
    scene->addItem(deck_text);

    //cards title
    QGraphicsTextItem * card_text = new QGraphicsTextItem("cards:");
    card_text->setFont(BODY_FONT);
    card_text->setDefaultTextColor(Qt::gray);
    scene->addItem(card_text);

    //magic deck title
    QGraphicsTextItem * magic_text = new QGraphicsTextItem("magic:");
    magic_text->setFont(BODY_FONT);
    magic_text->setPos(900, 450);
    magic_text->setDefaultTextColor(Qt::gray);
    scene->addItem(magic_text);

    //back button
    Button * back_button = new Button(QString("BACK"));
    back_button->setPos(600,700);
    scene->addItem(back_button);
    //connect back button to save deck, and then back to select window
    connect(back_button, SIGNAL(clicked()), this, SLOT(deck_save()));
    /**************************************/
}

void Game::deck_save(){
    //save deck
    for(int i=0; i<DECK_NUMBER; ++i){
        my_deck[i] = deck_manager->show_deck[i]->id;
    }

    //save magic deck
    my_magic = deck_manager->show_magic->id;

    save();
    select();
}
