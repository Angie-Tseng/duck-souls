#include "anounce.h"
#include <QFont>
#include <QTimer>

Anounce::Anounce(){
    setPos(730, 570);
    setDefaultTextColor(Qt::red);
    setFont(QFont("Courier New", 16));
    setOpacity(0);
}

void Anounce::set_anounce(QString text){
    setPlainText(text);
    setOpacity(1);
    setPos(x(), 570);
}
