#include <bits/stdc++.h>
using namespace std;

void func(int i,int j, int r, int c){
    // char ch=(97+j)%123;
    if(i%5==j%8 || i%5+j%8==8)cout<<char(j%26+'a');//repeat "and" to "or" cuz i and j will exceed r and c values 
    //to repeat after ending up to z in the v pattern take j%8 to get the pattern repeated
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
            func(i,j,r,c);//8 is sets to 0 and every thing next again is 0 1 2 3 ... 
        }
        cout<<"\n";
    }
    return 0;
}

