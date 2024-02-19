#include "ball.h"

Ball::Ball(int right_wall, int top_wall){
    x = 0;
    y = 0;
    dx = 1;
    dy = 1;
    max_x = right_wall;
    max_y = top_wall;

}

void Ball::move(){
    x += dx;
    y += dy;

    if(x == 0 || y == 0 || x == max_x || y == max_y){
        turn();
    }

}

void Ball::turn(){
    if(x== max_x || x == 0){
        dx = -dx;
    }
    if(y == max_y || y == 0){
        dy = -dy;
    }
}


int Ball::get_x() const{
    return x;
}

int Ball::get_y() const{
    return y;
}
