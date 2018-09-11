#include "deck.h"
#include "game_manager.h"
#include "card_information.h"

#include <QDebug>

extern GameManager * game_manager;

Deck::Deck(){}

Deck::Deck(int get_id, int number){
    setAcceptHoverEvents(true);

    //initialize deck
    setRect(0, 0, IMAGE_W, IMAGE_H);
    id = get_id;
    num = number;

    //set image
    image = new Minion_image();
    image->set_deck(id);

    //counter++
    ++deck_counter;
}

Deck::~Deck(){
    delete image;
    --deck_counter;
}

void Deck::set_id(int get_id){
    id = get_id;
    image->set_deck(id);
}

void Deck::set_num(int number)
{
    num = number;
}

void Deck::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug() << "click" << id;
    if(game_manager->player->send_minion(id)){
        game_manager->deck.erase(game_manager->deck.begin() + num);
        delete this;
        game_manager->draw();
    }
}


void Deck::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    info = new QGraphicsRectItem(this);
    info->setRect(0, 0, 150, 200);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkBlue);
    info->setBrush(brush);
    info->setOpacity(0.8);

    QGraphicsTextItem * info_text = new QGraphicsTextItem(info);
    info_text->setPos(10, 10);
    info_text->setDefaultTextColor(Qt::white);
    info_text->setFont(QFont("Times", 18));

    CardInfo * show_info = new CardInfo();
    if(id < 16){
        show_info->set_minion(id);
        info_text->setPlainText( QString("--- Minion ---")
                                +QString("\ncost: ") + QString::number(show_info->cost)
                                +QString("\nhp: ") + QString::number(show_info->hp)
                                +QString("\nattack: ") + QString::number(show_info->attack)
                                +QString("\nrange: ") + QString::number(show_info->range)
                                +QString("\nspeed: ") + QString::number(show_info->speed));
    }else{
        show_info->set_magic(id);
        info_text->setPlainText( QString("--- Magic ---")
                                +QString("\ncd: ") + QString::number(show_info->cd)
                                +QString("\ntime: ") + QString::number(show_info->time)
                                +QString("\nattack: ") + QString::number(show_info->attack)
                                +QString("\nrange: ") + QString::number(show_info->range));
    }
}

void Deck::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    info->setOpacity(0);
}
