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
void draw(vector<Snake_body> &arr, pair<int, int> food);
pair<int,int> random(int x, int y, vector<Snake_body> &arr);
bool is_safe(int x, int y, vector<Snake_body> &arr);


/*oid draw(Snake_body arr[], pair<int, int> food);
pair<int,int> random(int x, int y, Snake_body arr[]);
bool is_safe(int x, int y, Snake_body arr[]);*/
int main(){
    std::thread game(run);
    //game.start();
    while(!ext){
        getKeypress();
        //std::this_thread::sleep_for(std::chrono::seconds(1));
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
        Snake_body temp=arr[0];
        arr[0].x--;
        for(int i=arr.size()-1;i>1;i--){
            arr[i]=arr[i-1];
        }
        arr[1]=temp;
        //arr.pop_back();
    }else if(key==right){
        Snake_body temp=arr[0];
        arr[0].x++;
        for(int i=arr.size()-1;i>1;i--){
            arr[i]=arr[i-1];
        }
        arr[1]=temp;
        //arr.pop_back();
    }else if(key==up){
        Snake_body temp=arr[0];
        arr[0].y--;
        for(int i=arr.size()-1;i>1;i--){
            arr[i]=arr[i-1];
        }
        arr[1]=temp;
        //arr.pop_back();
    }else if(key==down){
        Snake_body temp=arr[0];
        arr[0].y++;
        for(int i=arr.size()-1;i>1;i--){
            arr[i]=arr[i-1];
        }
        arr[1]=temp;
        //arr.pop_back();
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
        //std::cout<<key<<std::endl;
        system("cls");
        /*for(int i=0;i<17;i++){
            std::cout<<'#';
        }*/
        std::cout<<std::endl;
        for(int i=0;i<15;i++){
            //std::cout<<'#';
            for(int j=0;j<15;j++){
                for(int k=0;k<arr.size();k++){
                    //std::cout<<arr[k].x<<","<<arr[k].y;
                    if(arr[k].x==j && arr[k].y==i){
                        std::cout<<'0';
                    }else{
                        std::cout<<" ";
                    }
                }
            }
            //std::cout<<'#';
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

