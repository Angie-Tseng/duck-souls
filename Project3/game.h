#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>
#include <string>
#include <cstdlib>
#include "button.h"
#include "deck_manager.h"

class Game: public QGraphicsView{
    Q_OBJECT

public:
    static const int WINDOW_X = 1600;
    static const int WINDOW_Y = 900;
    static const int CARD_NUMBER = 20;
    static const int DECK_NUMBER = 4;
    static const int LEVEL_NUMBER = 3;


    QGraphicsScene * scene;

    Game();
    ~Game();

    int current_level;
    int souls;
    int my_card[CARD_NUMBER];
    int my_deck[DECK_NUMBER];
    int my_magic;

public slots:
    //main_window
    void main_window();
    void new_game();

    //select window
    void select();

    //deck manager
    void deck_manager_window();
    void deck_save();

    //draw window
    void draw();
    void draw_clicked();

    //story window
    void map();
    void level_clicked();

    //game window(project2)
    void play(int ai_level);

    //game result window
    void result(bool is_win, int game_level, int add_souls);

private:
    QFont TITLE_FONT;
    QFont BODY_FONT;
    QFont COMMENT_FONT;

    void save();
    void load();

    DeckManager * deck_manager;
};

#endif // MAINWINDOW_H
