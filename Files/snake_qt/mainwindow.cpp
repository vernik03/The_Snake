#include "mainwindow.h"
#include "ui_mainwindow.h"
/*
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
QImage apple;
QImage def_tile;*/
bool is_in_menu=true;
 Game *newgame;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    menu.load(":/img/menu.png");
is_in_menu=true;
    ui->setupUi(this);
    this->setFixedSize(32*20, 32*23);
    this->ui->Play->setStyleSheet("QPushButton {  background: #86E4F9;"
                                  "box-shadow: 0px 5px 15px rgba(134, 228, 249, 0.75);"
                                  "border-radius: 5px;"
                                 "font-family: Comfortaa;"
                                  "font-style: normal;"
                                  "font-weight: bold;"
                                  "font-size: 25px;"
                                  "line-height: 31px;"
                                  "display: flex;"
                                  "align-items: center;"
                                  "text-align: center;"
                                  "color:white;}"
                                  "QPushButton:hover {  color: rgb(134,228,249);background-color:white; }");

    auto effect = new QGraphicsDropShadowEffect;
        effect->setBlurRadius(15);
        effect->setColor(QColor(134, 228, 249, 75));
        effect->setOffset(0,5);
       this->ui->Play->setGraphicsEffect(effect);




            this->ui->Exit->setStyleSheet("QPushButton {  background: #86E4F9;"
                                          "box-shadow: 0px 5px 15px rgba(134, 228, 249, 0.75);"
                                          "border-radius: 5px;"
                                         "font-family: Comfortaa;"
                                          "font-style: normal;"
                                          "font-weight: bold;"
                                          "font-size: 25px;"
                                          "line-height: 31px;"
                                          "display: flex;"
                                          "align-items: center;"
                                          "text-align: center;"
                                          "color:white;}"
                                          "QPushButton:hover {  color: rgb(134,228,249);background-color:white; }");
            auto effect3 = new QGraphicsDropShadowEffect;
                effect3->setBlurRadius(15);
                effect3->setColor(QColor(134, 228, 249, 75));
                effect3->setOffset(0,5);
               this->ui->Exit->setGraphicsEffect(effect3);

                record_score = new QLabel(this);
                record_score->setGeometry(212, 460, 216, 35);
                   record_score->setStyleSheet("font-family: Comfortaa;"
                                                 "font-style: normal;"
                                                 "font-weight: normal;"
                                                 "font-size: 29px;"
                                                 "line-height: 32px;"
                                                 "display: flex;"
                                                 "align-items: center;"
                                                 "text-align: center;"
                                                 "color: #86E4F9;");

                   record_score->setAlignment(Qt::AlignCenter);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Play_clicked()
{
     newgame = new Game(this);
    is_in_menu=false;
        newgame->show();
        this->hide();
}


void MainWindow::Draw() {


    QPainter qp(this);
    qp.drawImage(0, 0, menu);
    std::string s_r;
    QVector<int> v_max;
    std::ifstream in("results_list.txt");
        if (in.is_open())
        {
            while (getline(in, s_r))
            {
                v_max.push_back(stoi(s_r));
            }
        }
        in.close();
        std::sort (v_max.begin(), v_max.end());
        QString s_rec;
        if(v_max.size()>0){
     s_rec = QString::number(v_max[v_max.size()-1]);
       }
        else{
            s_rec=QString::number(0);
        }

         record_score->setText("your record: " + s_rec);
         record_score->show();


 }

void MainWindow::showEvent(QPaintEvent *e) {
   // newgame->close();
    delete newgame;

}

void MainWindow::paintEvent(QPaintEvent *e) {
    QPainter qp(this);
    Draw();
//    if(is_in_menu){
//        Draw();
//    }

}

void MainWindow::on_Exit_clicked()
{
    this->close();
}


void MainWindow::on_Leaderboard_clicked()
{

}

