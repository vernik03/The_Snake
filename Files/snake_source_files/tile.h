#ifndef TILE_H
#define TILE_H
#include <QWidget>
#include <QKeyEvent>
#include <QImage>
#include <QPainter>

class Tile
{
private:

public:
    Tile();
    Tile(int x_in, int y_in);
    void Draw();
    int get_state();
    int get_x();
    int get_y();
    int x;
    int y;
    int tile_state;

};

#endif // TILE_H

/*
#include "game.h"

Game::Game()
{
    my_board=new Board;
}

Board* Game::get_board(){
    return this->my_board;
}

#ifndef GAME_H
#define GAME_H
#include "board.h"
#include <QWidget>
#include <QKeyEvent>
#include <QImage>
#include <QPainter>
#include <QMainWindow>

class Game
{
    Q_OBJECT
private:
    Board* my_board;
public:
    Game();
    Board* get_board();
};

#endif // GAME_H

*/
