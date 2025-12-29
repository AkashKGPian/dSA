#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[4][5][6][9]{};
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<6;k++){
                for(int z=0;z<=9;z++){
                    cout<<arr[i][j][k][z]<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
     cout<<"\n";
    }
    cout<<"\n"<<"done";
}