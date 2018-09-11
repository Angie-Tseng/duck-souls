#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "show_mana.h"
#include "anounce.h"
#include "game_time.h"
#include "tower.h"

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Player();
    bool send_minion(int id);
    void keyPressEvent(QKeyEvent * event);
    Show_mana * show_mana;
    Anounce * anounce;
    Game_time * game_time;
    Tower * tower;

public slots:
    void add_mana();
    void fade();
};

#endif // PLAYER_H
