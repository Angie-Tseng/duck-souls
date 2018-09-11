#ifndef DECK_MANAGER_H
#define DECK_MANAGER_H

#include <QGraphicsRectItem>
#include <QObject>
#include "show_card.h"

class DeckManager: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    static const int CARD_NUMBER = 20;
    static const int DECK_NUMBER = 4;

    DeckManager(int my_card[], int my_deck[], int my_magic, QGraphicsItem * parent = NULL);

    int deck;
    ShowCard * show_card[CARD_NUMBER];
    ShowCard * show_deck[DECK_NUMBER];
    ShowCard * show_magic;

public slots:
    void card_clicked();
    void deck_clicked();
};

#endif // DECK_MANAGER_H
