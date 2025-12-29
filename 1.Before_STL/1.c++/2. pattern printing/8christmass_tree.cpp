#include <bits/stdc++.h>
using namespace std;

void func(int i, int j, int r, int c){
    if((i%5+j>=4 && i%5 >=j-4) || i%5==4)cout<<"*";//to ufill color ie "*" (i%5+j==4 || i%5 ==j-4) "or" comes 
    else cout<<" ";
    return ;
}

void func2(int i, int j, int r, int c){
    if( j>=3 && j<=5 )cout<<"*";
    else cout<<" ";
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0; j<c;j++){
            func(i,j,r,c);
        }
        cout<<"\n";
    }
    for(int i=0;i<r/5;i++){
        for(int j=0; j<c;j++){
            func2(i,j,r,c);
        }
        cout<<"\n";
    }

    return 0;
}
