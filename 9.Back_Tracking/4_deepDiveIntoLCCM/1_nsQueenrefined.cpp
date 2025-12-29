#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> queens;
int cnt;

bool is_on_eqn(int h, int k, int row, int col){
    int sX = row - h;
    int sY = col - k;
    if( (sX>=-3 && sX<=3) && (sY>=-3 && sY<=3)){
        if((abs(sY)-abs(abs(sX)-3))==0){//shifted eqn wrt h,k is that satisfed by the new shifted row and col
            return 1;
        }
    }
    return 0;
}

bool is_valid(int row, int col){
    for(int prow=0;prow<row;prow++){
        int pcol = queens[prow];
        if(pcol==col || abs(pcol-col)==abs(prow-row) || is_on_eqn(prow,pcol,row,col)){//first arg row is the level
            return 0;
        }
    }
    return 1;
}

void recfill(int level){
    if(level==n){
        cnt++;
        return;
    }
    for(int col=0;col<n;col++){
        if(is_valid(level,col)){
            queens.push_back(col);
            recfill(level+1);
            queens.pop_back();
        }
    }
}

int main(){
    cin>>n;
    recfill(0);
    cout<<cnt;
    return 0;
}