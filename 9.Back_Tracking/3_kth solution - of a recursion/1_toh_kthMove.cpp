#include <bits/stdc++.h>
using namespace std;

// int k;
int disc;//count of disc

void kthMove(int disc,int src,int aux,int target,int k){
    //move n-1 from src to aux
    if(k<=((1<<(disc-1))-1)){//(2^n-1) - 1
        kthMove(disc-1,src,target,aux,k);
    }
    //move 1 from src to target
    else if(k==(1<<(disc-1))){
        cout<<"Move the disc "<<disc<<" from "<<src<<" to "<<target<<".\n";
        return;
    }
    //move n-1 from aux to target//(2^n-1) - 1
    else{
        kthMove(disc-1,aux,src,target,k-(1<<(disc-1)));
    }
    return ;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>disc;//count of disc
    // cin>>k;
    // kthMove(disc,1,2,3,k);
    for(int i=1;i<=((1<<(disc))-1);i++){//2^n - 1
        kthMove(disc,1,2,3,i);
    }
    return 0;
}
