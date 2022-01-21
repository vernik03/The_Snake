#include "tile.h"


Tile::Tile()
{

}
Tile::Tile(int x_in, int y_in)
{
    tile_state=0;
    x=x_in;
    y=y_in;
}
int Tile::get_state(){
    return this->tile_state;
}
int Tile::get_x(){
    return this->x;
}
int Tile::get_y(){
    return this->y;
}
