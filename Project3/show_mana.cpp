#include "show_mana.h"
#include <QFont>

Show_mana::Show_mana(QGraphicsItem *parent){
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Times", 20));
    mana = 0;
    setPlainText(QString("mana: ") + QString::number(mana) + QString("/15"));
}

void Show_mana::increase(){
    //add mana until mana is full(= 10)
    if(mana >= 15) return;
    ++mana;
    setPlainText(QString("mana: ") + QString::number(mana) + QString("/15"));
}

void Show_mana::decrease(int x){
    //if sending minion success, decrease mana
    mana -= x;
    setPlainText(QString("mana: ") + QString::number(mana) + QString("/15"));
}

int Show_mana::get_mana(){
    return mana;
}
