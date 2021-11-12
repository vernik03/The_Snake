#ifndef GAME_H
#define GAME_H


#include "windows.h"
#include "board.h"
#include "snake.h"
#include "mainwindow.h"
#include "tile.h"
#include <string>
#include <iostream>
#include <fstream>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QKeyEvent>
#include <QImage>
#include <QPainter>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QQueue>
#include <QLabel>
#include <QFont>
#include <QPalette>
#include <QLayout>
#include <QPushButton>
#include <QApplication>
#include <QGraphicsDropShadowEffect>

class Game:public QMainWindow
{
    Q_OBJECT
private:
    Board* my_board;
    Snake* my_snake;
    int dir;
    bool playing;
    bool game_over;
    QString color;
      QTimer *timer;
    QQueue<int>  dir_queue;
    struct apple{
        int x;
        int y;
    };
    apple new_apple;
    int apple_count;
    QLabel counter;
    QMainWindow *win;
    QPushButton* pause_button;
     QPushButton* back_button;
     QPushButton* back_end_button;
     QPushButton* restart_button;
     QLabel* score;
      QLabel* record_score;
private slots:
    void slotTimerAlarm();
     void on_pause_button_clicked();
       void on_back_button_clicked();
       void on_back_end_button_clicked();
       void on_restart_button_clicked();
public:
    int scale;
   // Game();
    Game(QMainWindow* window);
    Board* get_board();
    Snake* get_snake_game();
    void game_turn();
    void rand_apple();    
    void game_init();
    QImage apple;
     QImage background;
      QImage bottom_panel;
       QImage arrow;
        QImage pause;
         QImage play;
          QImage game_over_img;
           QImage strawberry;
    bool eat_check();



protected:
    void paintEvent(QPaintEvent *);
    virtual void keyPressEvent(QKeyEvent *event);
};




#endif // GAME_H
