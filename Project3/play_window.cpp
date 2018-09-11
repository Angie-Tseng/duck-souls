#include "game.h"
#include "game_manager.h"

//this is for playing (project 2 here)

extern GameManager * game_manager;

void Game::play(int ai_level){
    qDebug() << "[game start] level " << ai_level;

    //hide the main window
    this->hide();

    //open the game manager and show
    game_manager = new GameManager(ai_level, my_deck, my_magic);
    game_manager->show();
}
