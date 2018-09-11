#ifndef AI_H
#define AI_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "show_mana.h"
#include "tower_ai.h"

class Ai: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Ai(int level);
    Show_mana * show_mana;
    Tower_ai * tower_ai;

public slots:
    void add_mana();
    void aquire();
    void set_pool(int level);

private:
    int pool;
};

#endif // AI_H
