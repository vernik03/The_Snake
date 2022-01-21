#ifndef SNAKE_H
#define SNAKE_H
#include <QVector>
#include <QPair>
#include <QImage>
#include "tile.h"
#include "snake_elem.h"


class Snake
{
private:



 QVector<snake_elem> snake;

public:

    Snake();
    void create_snake( QVector<snake_elem> &snake);
    void move_snake(int);
    void add_snake_elem(int);
    void check_pink();
    bool check_collision();
     QVector<snake_elem> get_snake();
     QImage head_up;
    QImage head_down;
    QImage head_left;
    QImage head_right;
    QImage tail_down;
     QImage tail_up;
    QImage tail_right;
     QImage tail_left;
     QImage body_horizontal;
     QImage body_vertical;
     QImage up_left;
     QImage up_right;
     QImage down_left;
     QImage down_right;

    QImage def_tile;

    QImage head_up_pink;
   QImage head_down_pink;
   QImage head_left_pink;
   QImage head_right_pink;
   QImage tail_down_pink;
    QImage tail_up_pink;
   QImage tail_right_pink;
    QImage tail_left_pink;
    QImage body_horizontal_pink;
    QImage body_vertical_pink;
    QImage up_left_pink;
    QImage up_right_pink;
    QImage down_left_pink;
    QImage down_right_pink;

};

#endif // SNAKE_H
