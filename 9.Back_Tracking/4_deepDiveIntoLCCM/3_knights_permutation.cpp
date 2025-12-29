#include <bits/stdc++.h>
using namespace std;

int n,k;
int board[14][14];
int cnt;

int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};

bool is_valid(int i, int j){
    if(board[i][j]==1)return 0;
    //if the new postion is attached by a prev knight its not possible to place over there
    //check the new post is it attacked by any of the prev knights placed till now
    //or even better rev eng
    //if at the new post if we keep knight would its 8 attacting pos attact any of the prev knight if so return 0 
    for(int pos=0;pos<8;pos++){
        int nx = i + dx[pos];
        int ny = j + dy[pos];
        if((nx>=0 && nx<n) && (ny>=0 && ny<n) && board[i][j]==1){//inside of board if it attacks any of the 
            return 0;
        }
    }
    return 1;
}

void recfill(int level){
    if(level==k){
        cnt++;
        return ;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(is_valid(i,j)){
                board[i][j]=1;
                recfill(level+1);
                board[i][j]=0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    recfill(0);
    //cnt/k! cuz cnt is the cnt of permution of arranging k1,k2...kk knights but we wanted the only way ie the combn 
    for(int i=1;i<=k;i++){
        cnt/=i;
    }
    cout<<cnt;
    return 0;
}
