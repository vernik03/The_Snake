#include "board.h"
#include "game.h"

Board::Board()
{
    tiles_w_h=new Tile*[width];
    for(int i=0; i<width;i++){
        tiles_w_h[i]=new Tile[height];
    }
    for(int i=0; i<width;i++){
         for(int j=0; j<height;j++){
            tiles_w_h[i][j]= Tile(i, j);
         }
    }

}

const int Board::get_width(){
    return this->width;
}


const int Board::get_height(){
     return this->height;
}

Tile** Board::get_tiles(){
    return this->tiles_w_h;
}
