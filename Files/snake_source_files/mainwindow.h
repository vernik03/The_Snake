#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "snake.h"
#include "tile.h"
#include <QWidget>
#include <QKeyEvent>
#include <QImage>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include "game.h"
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage menu;
  QLabel* record_score;

private slots:
    void on_Play_clicked();

    void on_Exit_clicked();

    void on_Leaderboard_clicked();

private:
    Ui::MainWindow *ui;

 bool is_in_menu;
     void Draw();


protected:

    void paintEvent(QPaintEvent *) ;
    void showEvent(QPaintEvent *) ;

};
#endif // MAINWINDOW_H
