#ifndef SHOW_CARD_H
#define SHOW_CARD_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QBrush>

//this is for showing cards in card manager

class ShowCard: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    static int select_id;

    ShowCard();
    ShowCard(int id, QGraphicsItem * parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

    void set_card(int id);
    void deck_color();
    void card_color();
    void clicked_color();

    QGraphicsTextItem * text;
    QGraphicsRectItem * panel;
    bool in_deck;
    int id;

signals:
    void clicked();

private:
    QGraphicsRectItem * info;
};

#endif // SHOW_CARD_H
