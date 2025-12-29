#include<bits/stdc++.h>
using namespace std;

int boardSize;//n2
int cellen;//n

vector<vector<int>> arr;

void printer(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool is_valid(int row, int col, int ch){
    for (int i = 0; i < boardSize; i++) {
        if (arr[row][i] == ch) return false; // check full row
        if (arr[i][col] == ch) return false; // check full column
    }
    // gives the coordinate of the cell
    int strow = row/cellen; 
    int stcol = col/cellen;
    int st_x = strow*cellen;
    int st_y = stcol*cellen;
    for(int i=st_x; i<(st_x+cellen); i++){
        for(int j=st_y; j<(st_y+cellen); j++){
            int pval = arr[i][j];
            if(pval==ch)return 0;
        }
    }
    return 1;
}

void recfill(int level){
    // cout<<level<<" : ";
    // printer();
    if(level==boardSize*boardSize){
        printer();
        cout<<"------\n";
        return ;
    }

    int row = level / boardSize;
    int col = level % boardSize;

    if (arr[row][col] != 0) {
        recfill(level + 1);
        return;
    }
    for (int ch = 1; ch <= boardSize; ch++) {
        if (is_valid(row, col, ch)) {
            arr[row][col] = ch;
            recfill(level + 1);
            arr[row][col] = 0;
        }
    }
}

int main(){
    cin>>boardSize;
    cellen=sqrt(boardSize);
    arr = vector<vector<int>>(boardSize,vector<int> (boardSize,0));
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"\n";
    recfill(0);
    
    return 0;
}