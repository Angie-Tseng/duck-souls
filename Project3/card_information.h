#ifndef CARD_INFORMATION_H
#define CARD_INFORMATION_H

#include <string>

//this is for setting the card information
class CardInfo{
public:
    CardInfo();

    void set_minion(int id);
    void set_magic(int id);

    //information:
    //general
    int id;
    int cost;
    int range;
    int attack;

    //for minion
    int hp;
    int speed;

    //for magic
    int cd;
    int time;
};

#endif // CARD_INFORMATION_H
