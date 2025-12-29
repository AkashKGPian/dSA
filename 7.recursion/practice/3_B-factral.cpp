#include<bits/stdc++.h>
using namespace std;

int n,k;

string patternOrg[3];
char finalarr[500][500];

void recfill(int x,int y,int len,char ch){
    if(ch=='*'){//black
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                finalarr[x+i][y+j]='*';
            }
        }
    }else{
        if(len!=1){
            //recursive case
            int newlen=len/n;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    recfill(x+i*newlen,y+j*newlen,newlen,patternOrg[i][j]);
                }
            }
        }else{
            finalarr[x][y]=ch;
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>patternOrg[i];
    }
    int len = round(pow(n,k));
    recfill(0,0,len,'.');
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            cout<<finalarr[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
 