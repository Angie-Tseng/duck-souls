#include "minion_image.h"
#include <QPixmap>
#include <QDebug>

Minion_image::Minion_image(QGraphicsPixmapItem *parent): QGraphicsPixmapItem(parent){
}


//for minion
void Minion_image::set_image(int id, QString from){
    setPixmap(QPixmap(QString(":/image/image/") + QString::number(id) + from + QString(".png")));
}


//for tower
void Minion_image::set_image(bool is_player){
    if(is_player)
        setPixmap(QPixmap(":/image/image/tower.png"));
    else
        setPixmap(QPixmap(":/image/image/tower_ai.png"));
}

void Minion_image::set_deck(int id){
    setPixmap(QPixmap(QString(":/image/image/") + QString::number(id) + QString("_deck.png")));
}

void Minion_image::set_bk(){
    setPixmap(QPixmap(":/image/image/background.png"));
}

void Minion_image::set_atk(QString from){
    setPixmap(QPixmap(QString(":/image/image/atk_") + from + QString(".gif")));
}
