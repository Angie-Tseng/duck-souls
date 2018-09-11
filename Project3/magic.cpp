#include "magic.h"
#include "card_information.h"
#include <QDebug>
#include <QFont>

Magic::Magic(int id){
    setRect(0, 0, 1600, 550);

    //show card
    magic_card = new ShowCard(id, this);
    magic_card->setPos(1150, 600);
    magic_card->setAcceptHoverEvents(false);

    //set cd text
    cd_text = new QGraphicsTextItem("", this);
    cd_text->setPos(1200, 650);
    cd_text->setFont(QFont("Times", 40));
    cd_text->setDefaultTextColor(Qt::red);

    //set information
    CardInfo * info = new CardInfo();
    info->set_magic(id);

    cd = 0;
    this->id = id;
    is_clicked = false;
    init_cd = info->cd;
    range = info->range;
    attack = info->attack;
    init_time = time = info->time;

    //connect magic card clicked
    connect(magic_card, SIGNAL(clicked()), this, SLOT(card_clicked()));

    //set timer
    timer = new QTimer();
    timer->start(1000);
}

void Magic::cold_down(){
    if(cd == 0){
        magic_card->card_color();
        cd_text->setPlainText("");
        disconnect(timer, SIGNAL(timeout()), this, SLOT(cold_down()));
        return;
    }

    --cd;
    cd_text->setPlainText(QString::number(cd));
}

void Magic::injure(){
    if(time == 0){
        attack_area->setVisible(false);
        disconnect(timer, SIGNAL(timeout()), this, SLOT(injure()));
        return;
    }
    --time;

    attack_area->attack_magic(attack);

}

void Magic::card_clicked(){
    if(cd != 0) return;
    is_clicked = !is_clicked;

    if(is_clicked)
        magic_card->clicked_color();
    else
        magic_card->card_color();
}

void Magic::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //if no magic card exits: do nothing

    //if not clicked in the game: do nothing
    if(event->pos().y() > 550) return;

    //if card not clicked: do nothing
    if(!is_clicked) return;

    //if cd != 0: do nothing
    if(cd != 0) return;

    //else: magic sent
    cd = init_cd;
    time = init_time;
    is_clicked = false;

    attack_area = new AttackMagic(id, event->pos().x(), range, this);
    attack_area->setVisible(true);
    magic_card->deck_color();
    cd_text->setPlainText(QString::number(cd));
    cold_down();
    injure();

    //connect cold_down and injure
    connect(timer, SIGNAL(timeout()), this, SLOT(cold_down()));
    connect(timer, SIGNAL(timeout()), this, SLOT(injure()));
    qDebug() << "send magic " << event->pos().x();
}
