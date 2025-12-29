#include <bits/stdc++.h>
using namespace std;

void toi(int n,char src, char aux, char dest){
    // if(n==1){
    //     cout<<"move disk :"<<n<<"from "<<src<<" to "<<dest<<"\n"; 
    //     return ;     
    // }or
    if(n==0){
        return ;
    }
    toi(n-1,src,dest,aux);
    cout<<"move disk :"<<n<<"from "<<src<<" to "<<dest<<"\n";
    toi(n-1,aux,src,dest);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    toi(n,'A','B','C');// A = source, B = auxiliary, C = destination
    return 0;
}
