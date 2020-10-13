#include <bits/stdc++.h>

using namespace std;

class Snake_body{
    public:
    int x, y;
    Snake_body(){
        x=y=0;
    }
    Snake_body(int x, int y){
        this->x=x;
        this->y=y;
    }
};

void move(Snake_body *arr){
}

void draw(Snake_body arr[], pair<int, int> food);
pair<int,int> random(int x, int y, Snake_body arr[]);
bool is_safe(int x, int y, Snake_body arr[]);
int main(){
    draw();
    move();
}