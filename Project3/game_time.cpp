#include "game_time.h"
#include <QFont>

Game_time::Game_time(){
    countdown = 180;
    setDefaultTextColor(Qt::white);
    setPos(700, 10);
    setFont(QFont("Arial Black", 36));
    setPlainText(QString::number(countdown)+QString(" secs"));
}

void Game_time::decrease(){
    countdown--;
    setPlainText(QString::number(countdown)+QString(" secs"));
}
