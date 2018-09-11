#include "show_card.h"
#include "card_information.h"
#include <QDebug>
#include <QFont>

ShowCard::ShowCard(){
}

ShowCard::ShowCard(int id, QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    setAcceptHoverEvents(true);

    text = new QGraphicsTextItem("");
    set_card(id);
    text->setPos(30, 50);

    QString file = QString(":/image/image/") + QString::number(id) + QString("_deck.png");
    setPixmap(QPixmap(file));

    panel = new QGraphicsRectItem(this);
    panel->setRect(0, 0, 150, 200);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    panel->setBrush(brush);
    panel->setOpacity(0);
}

void ShowCard::mousePressEvent(QGraphicsSceneMouseEvent *event){
    select_id = id;
    //when clicked: send the "clicked" signal.
    emit clicked();
}

void ShowCard::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
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

void ShowCard::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    info->setOpacity(0);
}

void ShowCard::set_card(int id){
    this->id = id;

    if(id == -1)
        text->setPlainText(" ");
    else
        text->setPlainText(QString::number(id));

    QString file = QString(":/image/image/") + QString::number(id) + QString("_deck.png");
    setPixmap(QPixmap(file));
}

void ShowCard::deck_color(){
    //if this card is in the deck -> changed color to darkgray
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    panel->setBrush(brush);
    panel->setOpacity(0.8);
}

void ShowCard::card_color(){
    //if this card is in the card -> changed color to white
    panel->setOpacity(0);
}

void ShowCard::clicked_color(){
    //if this card is clicked -> changed color to red
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    panel->setBrush(brush);
    panel->setOpacity(0.3);
}
