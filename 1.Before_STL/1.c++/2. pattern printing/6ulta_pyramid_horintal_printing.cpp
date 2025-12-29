#include <bits/stdc++.h>
using namespace std;

void func(int i,int j, int r, int c){
    if(i==j || i+j==8)cout<<"*";//repeat "and" to "or" cuz i and j will exceed r and c values 
    else cout<<".";
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
            func(i,j%8,r,c);//8 is sets to 0 and every thing next again is 0 1 2 3 ... 
        }
        cout<<"\n";
    }
    return 0;
}

