#ifndef GAME_TIME_H
#define GAME_TIME_H

#include <QGraphicsTextItem>

class Game_time: public QGraphicsTextItem{
public:
    Game_time();
    void decrease();
    int countdown;
};

#endif // GAME_TIME_H
