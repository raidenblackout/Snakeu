#include <bits/stdc++.h>
#include <thread>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <chrono>

enum keyCode{
    left='a',
    down='s',
    right='d',
    up='w'
};
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
std::atomic_int prev_key(0);
std::atomic_int key(0);
std::atomic_int ext(0);

void run();
void move(std::vector<Snake_body> &arr);
void getKeypress();
void draw(std::vector<Snake_body> &arr, std::pair<int, int> food);
std::pair<int,int> random(int length, int height, std::vector<Snake_body> &arr);
bool is_safe(int length, int height, std::vector<Snake_body> &arr);
int main(){
    std::thread game(run);
    while(!ext){
        getKeypress();
    }
    game.join();
}
void getKeypress(){
    int tkey=getch();
    //std::cout<<key<<std::endl;
    if(tkey==left &&  key!=right){
        key=left;
    }else if(tkey==right && key!=left){
        key=right;
    }else if(tkey==up && key!=down){
        key=up;
    }else if(tkey==down && key != up){
        key=down;
    }else if(tkey=='e'){
        ext=1;
    }
}
void move(std::vector<Snake_body> &arr){
    /*Need to fix something here. So just ignore this part and carry on with your work*/
    if(key==left){
        for(int i=arr.size()-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0].x--;
    }else if(key==right){
        for(int i=arr.size()-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0].x++;
    }else if(key==up){
        for(int i=arr.size()-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0].y--;
    }else if(key==down){
        for(int i=arr.size()-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0].y++;
    }
    
}
void run(){
    std::vector<Snake_body> arr;
    Snake_body temp(5,5);
    arr.push_back(temp);
    Snake_body t2(4,5);
    arr.push_back(t2);
    Snake_body t3(3,5);
    arr.push_back(t3);
    while(!ext){
        system("cls");
        for(int i=0;i<17;i++){
            std::cout<<'#';
        }
        std::cout<<std::endl;
        for(int i=0;i<15;i++){
            std::cout<<'#';
            for(int j=0;j<15;j++){
                bool f=0;
                if(arr[0].x==j && arr[0].y==i){
                    std::cout<<'X';
                    f=1;
                }
                for(int k=1;k<arr.size();k++){
                    //std::cout<<arr[k].x<<","<<arr[k].y;
                    if(arr[k].x==j && arr[k].y==i){
                        std::cout<<'0';
                        f=1;
                    }
                }
                if(!f){
                    std::cout<<' ';
                }

            }
            std::cout<<'#';
            std::cout<<std::endl;
        }
        for(int i=0;i<17;i++){
            std::cout<<'#';
        }
        for(auto a:arr){
            std::cout<<a.x<<","<<a.y<<" ";
        }
        std::cout<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        move(arr);
    }

}