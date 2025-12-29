#include <bits/stdc++.h>
using namespace std;

char func(int i,int j, int r, int c){
    if(i==0 || j==0 || i==r-1 || j ==c-1)return '*';
    else return ' ';
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<func(i,j,r,c);
        }
        cout<<"\n";
    }
    return 0;
}

