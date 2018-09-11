#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <vector>
using namespace std;

#include "player.h"
#include "ai.h"
#include "deck.h"
#include "button.h"
#include "magic.h"

class GameManager: public QGraphicsView{
    Q_OBJECT

public:
    const static int POOL_NUMBER = 4;
    const static int DECK_NUMBER = 4;

    static int add_souls;

    GameManager(int ai_level, int initial_pool[], int initial_magic);
    void game_over(bool is_win);
    void start();
    void draw();

    int pool[POOL_NUMBER];
    vector <Deck *> deck;
    QGraphicsScene * scene;
    Player * player;
    Ai * ai;
    Magic * magic;


    QTimer * player_timer;
    QTimer * ai_attack_timer;
    QTimer * move_timer;
    QTimer * attack_timer;
    QTimer * fade_timer;

public slots:
    void pre_game();
    void countdown();
    void pause();

private:
    const static int POOL_SIZE = 4;
    const static int IMAGE_W = 150;
    const static int WINDOW_X = 1600;
    const static int WINDOW_Y = 900;

    void align();
    void set_ai_timer();
    void draw_panel(int x, int y, int w, int h, QColor color, double opcacity);
    QGraphicsTextItem * show_count;

    int counter;
    int game_level;
    int magic_id;
    bool is_pause;
    Button * pause_button;
};

#endif // GAME_H
