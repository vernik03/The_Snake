#include "game.h"
#include "snake.h"


/*Game::Game()
{
}*/

void Game::game_init(){
    srand(time(NULL));
    dir = 1;
    dir_queue={};
    apple_count=0;
    playing=true;
    game_over=false;
    my_board=new Board;
    my_snake=new Snake;
    rand_apple();
    timer->start(100);
    restart_button->hide();
    back_end_button->hide();
    score->setGeometry(scale*6, scale*7.9, scale*8, scale*1);
    score->hide();
    record_score->hide();
    color="blue";
    if (int(rand()%5)==3){
        color="pink";
    }
}

Game::Game(QMainWindow* window){
      scale = 32; //45 / 32
  apple.load(":/img/apple.png");
  strawberry.load(":/img/strawberry.png");
  background.load(":/img/background.png");
   bottom_panel.load(":/img/bottom_panel.png");
   arrow.load(":/img/arrow.png");
   pause.load(":/img/pause.png");
    play.load(":/img/play.png");
    game_over_img.load(":/img/game_over_img.png");
    this->setGeometry(window->x(), window->y(), scale*20, scale*23);
    this->setFixedSize(scale*20, scale*23);
    counter.setGeometry(scale*3,scale*21,scale*3,scale);
     pause_button=new QPushButton(this);
     pause_button->setGeometry(scale*16, scale*21, scale, scale);
     pause_button->show();
 pause_button->setStyleSheet("background-color: rgba(0,0,0,0);");
 pause_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);

 QObject:connect(pause_button, SIGNAL(clicked()),this,SLOT(on_pause_button_clicked()));

 back_button=new QPushButton(this);
   back_button->setGeometry(scale*18, scale*21, scale, scale);
   back_button->show();
 back_button->setStyleSheet("background-color: rgba(0,0,0,0);");
 back_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);
 QObject2:connect(back_button, SIGNAL(clicked()),this,SLOT(on_back_button_clicked()));

 back_end_button=new QPushButton(this);
   back_end_button->setGeometry(scale*6, scale*14, scale*8, scale*2);
   back_end_button->setText("Back");
   back_end_button->setStyleSheet("QPushButton {  color: white; background-color: rgb(134,228,249); border-radius: 5px; font-family: Comfortaa; font-weight: bold;font-size: 28px; line-height: 35px; display: flex; align-items: center; text-align: center;}"
                                 "QPushButton:hover {  color: rgb(134,228,249);background-color:white; }");
   back_end_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);
   auto effect1 = new QGraphicsDropShadowEffect;
       effect1->setBlurRadius(17);
       effect1->setColor(QColor(13, 84, 100, 54));
       effect1->setOffset(0,5);
       back_end_button->setGraphicsEffect(effect1);
 QObject3:connect(back_end_button, SIGNAL(clicked()),this,SLOT(on_back_end_button_clicked()));

 restart_button=new QPushButton(this);
   restart_button->setGeometry(scale*6, scale*11, scale*8, scale*2);
   restart_button->setText("Restart");
 restart_button->setStyleSheet("QPushButton {  color: white; background-color: rgb(134,228,249); border-radius: 5px; font-family: Comfortaa; font-weight: bold;font-size: 28px; line-height: 35px; display: flex; align-items: center; text-align: center;}"
                               "QPushButton:hover {  color: rgb(134,228,249);background-color:white;}");

 restart_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);
 auto effect = new QGraphicsDropShadowEffect;
     effect->setBlurRadius(17);
     effect->setColor(QColor(13, 84, 100, 54));
     effect->setOffset(0,5);
     restart_button->setGraphicsEffect(effect);

 QObjectr:connect(restart_button, SIGNAL(clicked()),this,SLOT(on_restart_button_clicked()));

  score = new QLabel(this);

     score->setStyleSheet("font-family: Comfortaa;"
                                   "font-style: normal;"
                                   "font-weight: normal;"
                                   "font-size: 29px;"
                                   "line-height: 32px;"
                                   "display: flex;"
                                   "align-items: center;"
                                   "text-align: center;"
                                   "color: #FFFFFF;");

     score->setAlignment(Qt::AlignCenter);

     record_score = new QLabel(this);
     record_score->setGeometry(scale*6, scale*9.1, scale*8, scale*1);
        record_score->setStyleSheet("font-family: Comfortaa;"
                                      "font-style: normal;"
                                      "font-weight: normal;"
                                      "font-size: 29px;"
                                      "line-height: 32px;"
                                      "display: flex;"
                                      "align-items: center;"
                                      "text-align: center;"
                                      "color: #FFFFFF;");

        record_score->setAlignment(Qt::AlignCenter);




 this->setFocusPolicy(Qt::FocusPolicy::NoFocus);
 timer = new QTimer();
 connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));

 this->win=window;

  game_init();

}


void Game::slotTimerAlarm()
{
    if(playing){
        game_turn();
    }

}

void Game::paintEvent(QPaintEvent *e) {
    //counter.setText(QString::number(apple_count));
    if (color=="pink"){
        this->get_snake_game()->check_pink();

        }
    QPainter qp(this);
    // qp.drawImage(0, 0, background);

       int board_width=this ->get_board()->get_width();
       int board_height=this ->get_board()->get_height();
       Tile** board_tiles=this->get_board()->get_tiles();
       for(int i=0; i<board_width/2;i++){
            for(int j=0; j<board_height/2;j++){
                int tile_texture=board_tiles[i][j].get_state();
                QImage& curr_image(this->get_snake_game()->def_tile);
               qp.drawImage(scale*2*i, scale*2*j, curr_image);
            }
       }

       if (color=="pink"){
            qp.drawImage(scale*this->new_apple.x, scale*this->new_apple.y, strawberry);

           }else{
       qp.drawImage(scale*this->new_apple.x, scale*this->new_apple.y, apple);
        }


//        for(auto elem:this->get_snake_game()->get_snake()){
//           QImage& curr_image(get_snake_game()->def_tile);
//          qp.drawImage(scale*elem.get_x(), scale*elem.get_y(), elem.get_texture());

//       }

        for(int i=this->get_snake_game()->get_snake().size()-1; i>=0; i--){
           //QImage& curr_image(get_snake_game()->def_tile);
           qp.drawImage(scale*this->get_snake_game()->get_snake()[i].get_x(), scale*this->get_snake_game()->get_snake()[i].get_y(), this->get_snake_game()->get_snake()[i].get_texture());
        }
       //qp.drawImage(32*this->get_snake_game()->get_snake()[0].get_x(), 32*this->get_snake_game()->get_snake()[0].get_y(), this->get_snake_game()->get_snake()[0].get_texture());

       qp.drawImage(0, 0, bottom_panel);
       if (color=="pink"){
            qp.drawImage(scale, scale*21, strawberry);

           }else{
       qp.drawImage(scale, scale*21, apple);
        }

       QFont font("Comfortaa");
       font.setWeight(QFont::Bold);
       font.setPixelSize(30);
       qp.setFont(font);
       qp.setPen(Qt::white);
       qp.drawText(scale*3,scale*22-3, QString::number(apple_count));

       qp.drawImage(scale*18, scale*21, arrow);
       if(playing && !game_over){
        qp.drawImage(scale*16, scale*21, pause);
       }
       else if(!playing && !game_over){
           qp.drawImage(scale*16, scale*21, play);
       }
       if(game_over) {
            qp.drawImage(0, 0, game_over_img);
       }




}

Board* Game::get_board(){
    return this->my_board;
}


Snake* Game::get_snake_game(){
    return this->my_snake;
}




void Game::keyPressEvent(QKeyEvent *event){
    int temp_dir=0;
    int key=event->key();


    switch(key){
    case 16777234: {temp_dir=3;  break;}
    case 65: {temp_dir=3;  break;}
    case 1060: {temp_dir=3;  break;}
    case 16777235: {temp_dir=4;  break;}
    case 87: {temp_dir=4;  break;}
    case 1062: {temp_dir=4;  break;}
    case 16777236: {temp_dir=1;  break;}
    case 68: {temp_dir=1;  break;}
    case 1042: {temp_dir=1;  break;}
    case 16777237: {temp_dir=2;  break;}
    case 83: {temp_dir=2;  break;}
    case 1067: {temp_dir=2;break;}
    }
    if(temp_dir!=0){
    dir_queue.append(temp_dir);
    }
   //qDebug()<<QString::number(key);
}

void Game::on_pause_button_clicked()
{
   playing=!playing;
   repaint();
}

void Game::on_back_button_clicked()
{

    this->close();
     win->show();
}

void Game::on_back_end_button_clicked()
{

    this->close();
     win->show();
}

void Game::on_restart_button_clicked()
{

   game_init();
}




void Game::rand_apple(){
    bool flag=true;
    while(flag){
    this->new_apple.x=rand()%20;
    this->new_apple.y=rand()%20;
        flag=false;
        for(int i =0; i<this->get_snake_game()->get_snake().size(); i++){
            if (this->get_snake_game()->get_snake()[i].get_x()==this->new_apple.x&&this->get_snake_game()->get_snake()[i].get_y()==this->new_apple.y){
                flag=true;
            }
        }
    }

}

bool Game::eat_check(){
    if (this->get_snake_game()->get_snake()[0].get_x()==this->new_apple.x&&this->get_snake_game()->get_snake()[0].get_y()==this->new_apple.y){
        return true;
    }
    return false;
}

void Game::game_turn(){



    if(!dir_queue.isEmpty()){
        dir=dir_queue.back();
        dir_queue.pop_back();
    }
    if(!this->get_snake_game()->check_collision()){
        if (apple_count<40)
       {
           // -1.625*apple_count+100

          timer->start((500/(apple_count+7))+30);
       }
        else{
             timer->start(40);
        }


        if(!eat_check()){
            this->get_snake_game()->move_snake(dir);
        }
        else   {
            this->get_snake_game()->add_snake_elem(dir);
            apple_count++;
             rand_apple();
        }

    }
    else {
        playing=false;
        game_over=true;
        repaint();

         QString s = QString::number(apple_count);
         std::string s_r;
         int record_int;
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
          record_int=v_max[v_max.size()-1];
            }
             else{
                 s_rec=0;
                 record_int=0;
             }
          if (apple_count<=record_int){
              score->setText("your score: " + s);
              score->show();
             record_score->setText("your record: " + s_rec);
             record_score->show();
          }else{
               score->setGeometry(scale*6, scale*8.5, scale*8, scale*1);
              score->setText("New record: " + s);
              score->show();
          }

          std::ofstream out("results_list.txt", std::ios::app);
          out<<apple_count<<"\n";
           out.close();


         restart_button->show();
        back_end_button->show();

     //  Sleep(2000);
       //this->close();
       // win->show();

    }

     repaint();


}
