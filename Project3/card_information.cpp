#include "card_information.h"

//for setting the minion's information
CardInfo::CardInfo(){

}

void CardInfo::set_minion(int id){
    this->id = id;

    switch(id){
    case -1: break; //for nothing

    case 0:  cost = 1; hp = 1; attack = 1; range = 1; speed = 2; break;

    case 1:  cost = 1; hp = 1; attack = 2; range = 1; speed = 2; break;

    case 2:  cost = 1; hp = 2; attack = 1; range = 2; speed = 2; break;

    case 3:  cost = 2; hp = 3; attack = 2; range = 1; speed = 2; break;

    case 4:  cost = 2; hp = 2; attack = 1; range = 2; speed = 4; break;

    case 5:  cost = 3; hp = 3; attack = 3; range = 3; speed = 2; break;

    case 6:  cost = 3; hp = 3; attack = 2; range = 4; speed = 3; break;

    case 7:  cost = 3; hp = 5; attack = 4; range = 3; speed = 3; break;

    case 8:  cost = 4; hp = 4; attack = 3; range = 2; speed = 6; break;

    case 9:  cost = 4; hp = 4; attack = 3; range = 4; speed = 5; break;

    case 10: cost = 5; hp = 7; attack = 4; range = 1; speed = 2; break;

    case 11: cost = 6; hp = 5; attack = 7; range = 5; speed = 1; break;

    case 12: cost = 6; hp = 6; attack = 5; range = 2; speed = 3; break;

    case 13: cost = 7; hp = 6; attack = 6; range = 1; speed = 5; break;

    case 14: cost = 8; hp = 7; attack = 6; range = 3; speed = 4; break;

    case 15: cost = 9; hp = 10; attack = 7; range = 2; speed = 6; break;
    }

    hp *= 200;
    attack *= 10;
    speed *= 5;
    range *= 50;

}


//for setting the magic's information
void CardInfo::set_magic(int id){
    this->id = id;

    switch(id){
    case -1: range = 0; cd = 0; break; //for nothing

    case 16: attack = 2; range = 25; cd = 5; time = 5; break;

    case 17: attack = 15; range = 5; cd = 5; time = 1; break;

    case 18: attack = 5; range = 15; cd = 15; time = 10; break;

    case 19: attack = 20; range = 160; cd = 45; time = 1; break;
    }

    attack *= 50;
    range *= 20;
}
