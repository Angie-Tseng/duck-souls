#include "deck_manager.h"
#include <QDebug>

DeckManager::DeckManager(int my_card[], int my_deck[], int my_magic, QGraphicsItem *parent){
    /*** show cards ***/
    for(int i=0; i<CARD_NUMBER; ++i){

        //check if player has this card
        if(my_card[i] == 0)
            show_card[i] = new ShowCard(-1, this);
        else
            show_card[i] = new ShowCard(i, this);

        show_card[i]->setPos(50 + 150*(i%10), 50 + 200*(i/10));

        //check if is in the deck or magic deck
        show_card[i]->in_deck = false;

        for(int j=0; j<DECK_NUMBER; ++j){
            if(my_deck[j] == i){
                show_card[i]->in_deck = true;
                show_card[i]->deck_color();
                break;
            }
        }
        if(my_magic == i){
            show_card[i]->in_deck = true;
            show_card[i]->deck_color();
        }


        //connect cards to card_clicked()
        connect(show_card[i], SIGNAL(clicked()), this, SLOT(card_clicked()));
    }
    /******************/


    /*** show decks ***/
    for(int i=0; i<DECK_NUMBER; ++i){
        show_deck[i] = new ShowCard(my_deck[i], this);
        show_deck[i]->setPos(200 + 150*i, 450);

        //connect deck to card_clicked()
        connect(show_deck[i], SIGNAL(clicked()), this, SLOT(deck_clicked()));
    }
    /******************/


    /*** show magic deck ***/
    show_magic = new ShowCard(my_magic, this);
    show_magic->setPos(1100, 450);

    //connect magic to card_clicked()
    connect(show_magic, SIGNAL(clicked()), this,SLOT(deck_clicked()));
    /***********************/

}


void DeckManager::card_clicked(){
    //if player clicks a card
    int id = ShowCard().select_id;
    qDebug() << "card " << id;

    //if the card is empty: do nothing
    if(id == -1)
        return;

    /*** for id 0~15: minion ***/
    if(id <= 15){
        for(int i=0; i<DECK_NUMBER; ++i)
            //if the card is already in the deck: do nothing
            if(show_deck[i]->id == id) return;


        //else: put this card in to deck
        for(int i=0; i<DECK_NUMBER; ++i)
            if(show_deck[i]->id == -1){
                show_card[id]->deck_color();
                show_deck[i]->set_card(id);
                return;
            }

        //if the deck is full: do nothing
        return;
    }
    /***************************/


    /*** for id 16~19: magic ***/
    //if the magic is already in the magic deck: do nothing
    if(show_magic->id == id) return;

    //else: put this card in to magic deck
    if(show_magic->id == -1){
        show_card[id]->deck_color();
        show_magic->set_card(id);
        return;
    }
    //if the magic deck is full: do nothing
    /***************************/
}

void DeckManager::deck_clicked(){
    //if player clicks a deck
    int id = ShowCard().select_id;
    qDebug() << "deck " << id;

    //if the deck is empty: do nothing
    if(id == -1)
        return;

    //else: put this deck back to card
    show_card[id]->set_card(id);
    show_card[id]->card_color();


    //if clicked magic deck
    if(id > 15){
        show_magic->set_card(-1);
        return;
    }

    for(int i=0; i<DECK_NUMBER; ++i)
        if(show_deck[i]->id == id){
            show_deck[i]->set_card(-1);
            break;
        }
}
