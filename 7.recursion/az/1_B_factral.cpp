#include <bits/stdc++.h>
using namespace std;

//B.factral - cf

int n,k;
string pattern[3];
//3^5 <= 500  
string finalarr[500][500];

void recfill(int x,int y, int len, char ch){
    //fill sq (x,y).. to (x+len-1,y+len-1) with character ch
    if(ch=='*'){
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                finalarr[x+i][y+j]='*';
            }
        }
    }else{
        if(len!=1){
            int newlen=len/n;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    recfill(x+i*newlen,y+j*newlen,newlen,pattern[i][j]);
                }
            }
        }else{
            finalarr[x][y]=ch;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>pattern[i];
    }

    int len=round(pow(n,k));

    recfill(0,0,len,'.');
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            cout<<finalarr[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
