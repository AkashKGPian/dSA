#include <bits/stdc++.h>
using namespace std;

int board[4][4];

int get_random(int x){
    return rand()%x;    
}

void random_spawn(){
    //rejection sampling
    while(1){
        int x = get_random(4);
        int y = get_random(4);
        if(board[x][y]==0){
            int random_temp = get_random(4);//generates 0 1 2 and 3
            if(random_temp==0 || random_temp==1 || random_temp==2)board[x][y]=2;//picking up 2 with a probablity of 0.75
            else board[x][y]=4;
            return;
        }
    }       
}

void setup_game(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            board[i][j]=0;
        }
    }
    random_spawn();
    random_spawn();
    return ;
}

// void random_spawn_2 --> fill all the empty cell in an array and pick an index randomly use stl

void swipe(int arr[]){
    int last=4;
    int is_last_fixed=1;
    for(int curr=3; curr>=0;curr--){
        if(arr[curr]==0)continue;
        if(is_last_fixed){
            // z....x ->  ...zx
            arr[last-1]=arr[curr];
            if(curr!=last-1)arr[curr]=0;//but why
            last--;
            is_last_fixed=0;
        }else{
            //x..x -> ...2x
            if(arr[last]==arr[curr]){
                arr[last]+=arr[curr];
                arr[curr]=0;
                is_last_fixed=1;
            }else{
                // z....x ->  ...zx
                arr[last-1]=arr[curr];
                if(curr!=last-1)arr[curr]=0;//but why
                last--;
                is_last_fixed=0;
            }
        }
    }
}
