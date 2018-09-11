#include <QApplication>
#include <ctime>

#include "game.h"
#include "game_manager.h"

#include "show_card.h"
#include "show_level.h"
#include "deck.h"

int ShowCard::select_id = 0;
int ShowLevel::select_level = 0;
int Deck::deck_counter = 0;
int GameManager::add_souls = 0;


Game * game;
GameManager * game_manager;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //initialize timestamp for random
    srandom(time(NULL));

    //show game window
    game = new Game();
    game->show();

    return a.exec();
}
