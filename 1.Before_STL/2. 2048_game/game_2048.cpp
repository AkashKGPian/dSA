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
            if(random_temp==0 || random_temp==1 || random_temp==2)
                board[x][y]=2;//picking up 2 with a probablity of 0.75
            else 
                board[x][y]=4;
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

int check_game_end(){
    // 0 -> Not ended.  1-> Ended and Win . 2-> Ended and lose.
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==2048){
                return 1;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==0){
                return 0;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j+1<4&&board[i][j]==board[i][j+1]){
                return 0;
            }
            if(i+1<4&&board[i][j]==board[i+1][j]){
                return 0;
            }
        }
    }
    return 2;
}


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

void move_up(){//correct
    for(int j=0;j<4;j++){
        int arr[4];
        for(int i=0;i<4;i++){
            arr[i]=board[3-i][j];
        }
        swipe(arr);
        for(int i=0;i<4;i++){
            board[3-i][j]=arr[i];
        }
    }
}

void move_left(){
    for(int i=0;i<4;i++){
        int arr[4];
        for(int j=0;j<4;j++){
            arr[j]=board[i][3-j];
        }
        swipe(arr);
        for(int j=0;j<4;j++){
            board[i][3-j]=arr[j];
        }
    }
}

void move_right(){
    for(int i=0;i<4;i++){
        int arr[4];
        for(int j=0;j<4;j++){
            arr[j]=board[i][j];
        }
        swipe(arr);
        for(int j=0;j<4;j++){
            board[i][j]=arr[j];
        }
    }
}


void move_down(){//correct
    for(int j=0;j<4;j++){
        int arr[4];
        for(int i=0;i<4;i++){
            arr[i]=board[i][j];
        }
        swipe(arr);
        for(int i=0;i<4;i++){
            board[i][j]=arr[i];
        }
    }
}

void display(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==0)cout<<"_ ";
            else cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    setup_game();
    while(!(check_game_end())){
        display();

        cout<<"What move to do? (A,D,W,S)";
        char ch;
        cin>>ch;

        // save old board.
        int temp[4][4];
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                temp[i][j] = board[i][j];
            }
        }
        
        if(ch=='A' || ch=='a'){
            move_left();
        }else if(ch=='D' || ch=='d'){
            move_right();
        }else if(ch=='W' || ch=='w'){
            move_up();
        }else if(ch=='S' || ch=='s'){
            move_down();
        }else{
            cout<<"Invalid move";
            continue;
        }
        // Check if it changed... or else its invalid.
        bool changed = 0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(temp[i][j] != board[i][j]){
                    changed=1;
                    break;
                }
            }
        }
        if(changed){
            random_spawn();
        }else{
            cout<<"Invalid Move.";
            continue;
        }        
    }

    return 0;
}
