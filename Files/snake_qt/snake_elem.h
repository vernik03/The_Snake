#ifndef SNAKE_ELEM_H
#define SNAKE_ELEM_H
#include <QImage>


class snake_elem
{
    int x;
    int y;
    int prev_dir;
    int next_dir;
    QImage texture;
public:

    snake_elem();
    int get_x();
    int get_y();
    int get_prev_dir();
    int get_next_dir();
    QImage get_texture();
    void set_x(int);
    void set_y(int);
    void set_prev_dir(int);
    void set_next_dir(int);
    void set_texture(QImage);
};

#endif // SNAKE_ELEM_H
