#include "snake_elem.h"
#include <QImage>
snake_elem::snake_elem()
{

}


int snake_elem::get_x(){
    return this->x;
}
int snake_elem::get_y(){
    return this->y;
}

int snake_elem::get_prev_dir(){
    return this->prev_dir;
}
int snake_elem::get_next_dir(){
    return this->next_dir;
}
QImage snake_elem::get_texture(){
    return this->texture;
}


void snake_elem::set_x(int x_in){
    this->x=x_in;
}
void snake_elem::set_y(int y_in){
    this->y=y_in;
}

void snake_elem::set_prev_dir(int x_in){
    this->prev_dir=x_in;
}
void snake_elem::set_next_dir(int y_in){
    this->next_dir=y_in;
}
void snake_elem::set_texture(QImage texture_in){
    this->texture=texture_in;
}


