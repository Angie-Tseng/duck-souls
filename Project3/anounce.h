#ifndef ANOUNCE_H
#define ANOUNCE_H

#include <QGraphicsTextItem>

class Anounce: public QGraphicsTextItem{
public:
    Anounce();
    void set_anounce(QString text);
};

#endif // ANOUNCE_H
