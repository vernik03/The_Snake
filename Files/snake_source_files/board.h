#ifndef BOARD_H
#define BOARD_H
#include "tile.h"

class Board
{
private:
    const static int width = 20;
    const static int height = 20;
    Tile** tiles_w_h;
public:
    Board();
    const int get_width();
    const int get_height();
    Tile** get_tiles();

};

#endif // BOARD_H
