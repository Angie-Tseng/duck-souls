#ifndef MAGIC_H
#define MAGIC_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QTimer>
#include "show_card.h"
#include "attack_magic.h"

class Magic: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Magic(int id);
    ShowCard * magic_card;
    AttackMagic * attack_area;
    QGraphicsTextItem * cd_text;
    QTimer * timer;

public slots:
    void cold_down();
    void injure();
    void card_clicked();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

private:
    int id;
    int attack;
    int range;
    int cd;
    int init_cd;
    int time;
    int init_time;

    bool is_clicked;
};

#endif // MAGIC_H
