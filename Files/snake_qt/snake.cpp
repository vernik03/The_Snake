#include "snake.h"
#include <QDebug>


Snake::Snake()
{
    //QVector<Tile*> s=this->get_snake();
    //this->create_snake(s);
    head_up.load(":/img/head_up.png");
    head_down.load(":/img/head_down.png");
    head_left.load(":/img/head_left.png");
    head_right.load(":/img/head_right.png");
    tail_down.load(":/img/tail_down.png");
    tail_up.load("://img/tail_up.png");
    tail_right.load(":/img/tail_right.png");
    tail_left.load(":/img/tail_left.png");
    body_horizontal.load(":/img/body_horizontal.png");
    body_vertical.load(":/img/body_vertical.png");
    up_left.load(":/img/top_left.png");
    up_right.load(":/img/top_right.png");
    down_left.load(":/img/down_left.png");
    down_right.load(":/img/down_right.png");
    def_tile.load(":/img/default.png");

    head_up_pink.load(":/img/head_up_pink.png");
    head_down_pink.load(":/img/head_down_pink.png");
    head_left_pink.load(":/img/head_left_pink.png");
    head_right_pink.load(":/img/head_right_pink.png");
    tail_down_pink.load(":/img/tail_down_pink.png");
    tail_up_pink.load("://img/tail_up_pink.png");
    tail_right_pink.load(":/img/tail_right_pink.png");
    tail_left_pink.load(":/img/tail_left_pink.png");
    body_horizontal_pink.load(":/img/body_horizontal_pink.png");
    body_vertical_pink.load(":/img/body_vertical_pink.png");
    up_left_pink.load(":/img/top_left_pink.png");
    up_right_pink.load(":/img/top_right_pink.png");
    down_left_pink.load(":/img/down_left_pink.png");
    down_right_pink.load(":/img/down_right_pink.png");

    create_snake(this->snake);

}


QVector<snake_elem> Snake::get_snake(){
    return this->snake;
}

void Snake::create_snake(QVector<snake_elem>&snake){

    snake_elem new_snake_elem;
    new_snake_elem.set_texture(head_right);
    new_snake_elem.set_x(5);
    new_snake_elem.set_y(5);
    new_snake_elem.set_prev_dir(1);
    new_snake_elem.set_next_dir(1);
    snake.push_back(new_snake_elem);
    snake_elem new_snake_elem2;
    new_snake_elem2.set_texture(body_horizontal);
    new_snake_elem2.set_x(4);
    new_snake_elem2.set_y(5);
    new_snake_elem2.set_prev_dir(1);
    new_snake_elem2.set_next_dir(1);
    snake.push_back(new_snake_elem2);
//    snake_elem new_snake_elem4;
//    new_snake_elem4.set_texture(down_right);
//    new_snake_elem4.set_x(3);
//    new_snake_elem4.set_y(5);
//    new_snake_elem4.set_prev_dir(1);
//    new_snake_elem4.set_next_dir(4);
//    snake.push_back(new_snake_elem4);
//    snake_elem new_snake_elem5;
//    new_snake_elem5.set_texture(body_vertical);
//    new_snake_elem5.set_x(3);
//    new_snake_elem5.set_y(6);
//    new_snake_elem5.set_prev_dir(4);
//    new_snake_elem5.set_next_dir(4);
//    snake.push_back(new_snake_elem5);
    snake_elem new_snake_elem3;
    new_snake_elem3.set_texture(tail_right);
    new_snake_elem3.set_x(3);
    new_snake_elem3.set_y(5);
    new_snake_elem3.set_prev_dir(1);
    new_snake_elem3.set_next_dir(1);
    snake.push_back(new_snake_elem3);

}

void Snake::check_pink(){
    for(int i =0; i<this->snake.size(); i++)
    {

        if (snake[i].get_texture()==head_up){
            this->snake[i].set_texture(head_up_pink);
        }
        else if(snake[i].get_texture()==head_down){
            this->snake[i].set_texture(head_down_pink);
        }
        else if(snake[i].get_texture()==head_left){
            this->snake[i].set_texture(head_left_pink);
        }
        else if(snake[i].get_texture()==head_right){
            this->snake[i].set_texture(head_right_pink);
        }
        else if(snake[i].get_texture()==body_horizontal){
            this->snake[i].set_texture(body_horizontal_pink);
        }
        else if(snake[i].get_texture()==body_vertical){
            this->snake[i].set_texture(body_vertical_pink);
        }
        else if(snake[i].get_texture()==tail_down){
            this->snake[i].set_texture(tail_down_pink);
        }
        else if(snake[i].get_texture()==tail_up){
            this->snake[i].set_texture(tail_up_pink);
        }
        else if(snake[i].get_texture()==tail_right){
            this->snake[i].set_texture(tail_right_pink);
        }
        else if(snake[i].get_texture()==tail_left){
            this->snake[i].set_texture(tail_left_pink);
        }
        else if(snake[i].get_texture()==up_left){
            this->snake[i].set_texture(up_left_pink);
        }
        else if(snake[i].get_texture()==up_right){
            this->snake[i].set_texture(up_right_pink);
        }
        else if(snake[i].get_texture()==down_left){
            this->snake[i].set_texture(down_left_pink);
        }
        else if(snake[i].get_texture()==down_right){
            this->snake[i].set_texture(down_right_pink);
        }

    }


}

void Snake::add_snake_elem(int rot){
    snake_elem new_snake_elem;
    new_snake_elem.set_texture(head_up);
    new_snake_elem.set_x(snake[0].get_x());
    new_snake_elem.set_y(snake[0].get_y());
    new_snake_elem.set_prev_dir(snake[0].get_prev_dir());
    new_snake_elem.set_next_dir(snake[0].get_next_dir());

    switch (rot) {
        case 1:
          new_snake_elem.set_x(new_snake_elem.get_x()+1);
          new_snake_elem.set_texture(head_right);
        new_snake_elem.set_next_dir(1);
        new_snake_elem.set_prev_dir(1);

        break;
    case 2:
        new_snake_elem.set_y(new_snake_elem.get_y()+1);
          new_snake_elem.set_texture(head_down);
       new_snake_elem.set_next_dir(2);
      new_snake_elem.set_prev_dir(2);
    break;
    case 3:
         new_snake_elem.set_x(new_snake_elem.get_x()-1);
        new_snake_elem.set_texture(head_left);
       new_snake_elem.set_next_dir(3);
       new_snake_elem.set_prev_dir(3);
    break;
    case 4:
       new_snake_elem.set_y(new_snake_elem.get_y()-1);
        new_snake_elem.set_texture(head_up);
       new_snake_elem.set_next_dir(4);
        new_snake_elem.set_prev_dir(4);
    break;
    }

     std::reverse( this->snake.begin(), this->snake.end() );
     this->snake.push_back(new_snake_elem);
     std::reverse( this->snake.begin(), this->snake.end() );

     for(int i =1; i<this->snake.size()-1; i++)
     {

         snake[i].set_next_dir(snake[i+1].get_prev_dir());
         snake[i].set_prev_dir(snake[i-1].get_next_dir());

     }

     snake[snake.size()-1].set_next_dir(snake[snake.size()-2].get_prev_dir());
     snake[snake.size()-1].set_prev_dir(snake[snake.size()-2].get_next_dir());

     for(int i =1; i<this->snake.size(); i++)
     {

         if ((snake[i].get_prev_dir()==2 && snake[i].get_next_dir()==2)||(snake[i].get_prev_dir()==4 && snake[i].get_next_dir()==4))
              this->snake[i].set_texture(body_vertical);
         else if ((snake[i].get_prev_dir()==3 && snake[i].get_next_dir()==3)||(snake[i].get_prev_dir()==1 && snake[i].get_next_dir()==1))
              this->snake[i].set_texture(body_horizontal);
         else if ((snake[i].get_prev_dir()==1 && snake[i].get_next_dir()==4)||(snake[i].get_prev_dir()==2 && snake[i].get_next_dir()==3))
              this->snake[i].set_texture(down_right);
         else if ((snake[i].get_prev_dir()==2 && snake[i].get_next_dir()==1)||(snake[i].get_prev_dir()==3 && snake[i].get_next_dir()==4))
              this->snake[i].set_texture(down_left);
         else if ((snake[i].get_prev_dir()==1 && snake[i].get_next_dir()==2)||(snake[i].get_prev_dir()==4 && snake[i].get_next_dir()==3))
              this->snake[i].set_texture(up_right);
         else if ((snake[i].get_prev_dir()==4 && snake[i].get_next_dir()==1)||(snake[i].get_prev_dir()==3 && snake[i].get_next_dir()==2))
              this->snake[i].set_texture(up_left);

     }
     if (snake[snake.size()-1].get_prev_dir()==1)
          this->snake[snake.size()-1].set_texture(tail_right);
     else if (snake[snake.size()-1].get_prev_dir()==2)
          this->snake[snake.size()-1].set_texture(tail_down);

     else if (snake[snake.size()-1].get_prev_dir()==3)
          this->snake[snake.size()-1].set_texture(tail_left);

     else if (snake[snake.size()-1].get_prev_dir()==4)
          this->snake[snake.size()-1].set_texture(tail_up);

     for(int i =0; i<this->snake.size(); i++){
         if (snake[i].get_x()>19){
             snake[i].set_x(0);
         }
         else if(snake[i].get_x()<0){
              snake[i].set_x(19);
         }
         if (snake[i].get_y()>19){
             snake[i].set_y(0);
         }
         else if(snake[i].get_y()<0){
              snake[i].set_y(19);
         }

     }



}

void Snake::move_snake(int rot){

    for(int i =this->snake.size()-1; i>0; i--)
    {
        this->snake[i]=this->snake[i-1];
    }
    if(abs(snake[0].get_next_dir()-rot)!=2)
    {
    switch (rot) {
        case 1:
          this->snake[0].set_x(this->snake[0].get_x()+1);
          this->snake[0].set_texture(head_right);
        snake[0].set_next_dir(1);
        snake[0].set_prev_dir(1);

        break;
    case 2:
        this->snake[0].set_y(this->snake[0].get_y()+1);
          this->snake[0].set_texture(head_down);
        snake[0].set_next_dir(2);
        snake[0].set_prev_dir(2);
    break;
    case 3:
          this->snake[0].set_x(this->snake[0].get_x()-1);
         this->snake[0].set_texture(head_left);
        snake[0].set_next_dir(3);
        snake[0].set_prev_dir(3);
    break;
    case 4:
        this->snake[0].set_y(this->snake[0].get_y()-1);
          this->snake[0].set_texture(head_up);
        snake[0].set_next_dir(4);
        snake[0].set_prev_dir(4);
    break;
    default:
        break;
    }
    }else  {
         switch (snake[0].get_next_dir()) {
        case 1:
          this->snake[0].set_x(this->snake[0].get_x()+1);
        break;
    case 2:
        this->snake[0].set_y(this->snake[0].get_y()+1);
    break;
    case 3:
          this->snake[0].set_x(this->snake[0].get_x()-1);
    break;
    case 4:
        this->snake[0].set_y(this->snake[0].get_y()-1);
    break;
      }
    }
    for(int i =1; i<this->snake.size()-1; i++)
    {

        snake[i].set_next_dir(snake[i+1].get_prev_dir());
        snake[i].set_prev_dir(snake[i-1].get_next_dir());

    }

    snake[snake.size()-1].set_next_dir(snake[snake.size()-2].get_prev_dir());
    snake[snake.size()-1].set_prev_dir(snake[snake.size()-2].get_next_dir());

    for(int i =1; i<this->snake.size(); i++)
    {

        if ((snake[i].get_prev_dir()==2 && snake[i].get_next_dir()==2)||(snake[i].get_prev_dir()==4 && snake[i].get_next_dir()==4))
             this->snake[i].set_texture(body_vertical);
        else if ((snake[i].get_prev_dir()==3 && snake[i].get_next_dir()==3)||(snake[i].get_prev_dir()==1 && snake[i].get_next_dir()==1))
             this->snake[i].set_texture(body_horizontal);
        else if ((snake[i].get_prev_dir()==1 && snake[i].get_next_dir()==4)||(snake[i].get_prev_dir()==2 && snake[i].get_next_dir()==3))
             this->snake[i].set_texture(down_right);
        else if ((snake[i].get_prev_dir()==2 && snake[i].get_next_dir()==1)||(snake[i].get_prev_dir()==3 && snake[i].get_next_dir()==4))
             this->snake[i].set_texture(down_left);
        else if ((snake[i].get_prev_dir()==1 && snake[i].get_next_dir()==2)||(snake[i].get_prev_dir()==4 && snake[i].get_next_dir()==3))
             this->snake[i].set_texture(up_right);
        else if ((snake[i].get_prev_dir()==4 && snake[i].get_next_dir()==1)||(snake[i].get_prev_dir()==3 && snake[i].get_next_dir()==2))
             this->snake[i].set_texture(up_left);
    }
    if (snake[snake.size()-1].get_prev_dir()==1)
         this->snake[snake.size()-1].set_texture(tail_right);
    else if (snake[snake.size()-1].get_prev_dir()==2)
         this->snake[snake.size()-1].set_texture(tail_down);

    else if (snake[snake.size()-1].get_prev_dir()==3)
         this->snake[snake.size()-1].set_texture(tail_left);

    else if (snake[snake.size()-1].get_prev_dir()==4)
         this->snake[snake.size()-1].set_texture(tail_up);

    for(int i =0; i<this->snake.size(); i++){
        if (snake[i].get_x()>19){
            snake[i].set_x(0);
        }
        else if(snake[i].get_x()<0){
             snake[i].set_x(19);
        }
        if (snake[i].get_y()>19){
            snake[i].set_y(0);
        }
        else if(snake[i].get_y()<0){
             snake[i].set_y(19);
        }

    }


}


bool Snake::check_collision(){
    for(int i =1; i<this->snake.size(); i++){
        if (snake[i].get_x()==snake[0].get_x()&&snake[i].get_y()==snake[0].get_y()){
            return true;
        }
    }
    return false;
}
