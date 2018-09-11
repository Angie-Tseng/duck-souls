#include "game.h"

//this is for starting a new game

void Game::new_game(){
    current_level = 0;                                  //set current_level (story level) = 0
    souls = 0;                                          //set souls = 0
    for(int i=0; i<CARD_NUMBER; ++i) my_card[i] = 0;    //set the initial cards player have
    for(int i=0; i<DECK_NUMBER; ++i) my_card[i] = 1;
    for(int i=0; i<DECK_NUMBER; ++i) my_deck[i] = i;    //set the initial deck
    my_magic = -1;                                      //set magic card in deck = 0 (no magic card)

    save();

    select();
}
