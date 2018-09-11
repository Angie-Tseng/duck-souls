#include "game.h"
#include <fstream>
#include <iostream>
using namespace std;

//this is for loading/saving the save_file

void Game::load(){
    string file_name = "save_file";
    ifstream load_file(file_name, ios::in);

    string tag;

    load_file >> tag;   //current level
    load_file >> current_level;

    load_file >> tag;   //souls
    load_file >> souls;

    load_file >> tag;   //player's card
    for(int i=0; i<CARD_NUMBER; ++i) load_file >> my_card[i];

    load_file >> tag;   //player's deck
    for(int i=0; i<DECK_NUMBER ;++i) load_file >> my_deck[i];

    load_file >> tag;   //player's magic card
    load_file >> my_magic;

    qDebug() << " game loaded.";
}



void Game::save(){
    string file_name = "save_file";

    //find the saving file
    ofstream file(file_name, ios::out);

    //if not found: create the saveing file
    if(!file){
        qDebug() << "failed saving file";
    }

    file << "current_level " << current_level << endl   //save current_level
         << "souls "         << souls         << endl   //save souls
         << "my_card ";
    for(int i=0; i<CARD_NUMBER; ++i) file << my_card[i] << " "; //save the card player have

    file << endl
         << "my_deck ";

    for(int i=0; i<DECK_NUMBER; ++i) file << my_deck[i] << " ";   //save player's deck

    file << endl
         << "my_magic " << my_magic << endl;            //save player's magic card


    qDebug() << " game saved.";
}
