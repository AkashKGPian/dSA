#include <bits/stdc++.h>
using namespace std;

void func(int i,int j, int r, int c){
    if(i+j>=4 && i>=j-4)cout<<"*";
    else cout<<" ";
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r,c;//5*9
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            func(i,j,r,c);
        }
        cout<<"\n";
    }
    return 0;
}
