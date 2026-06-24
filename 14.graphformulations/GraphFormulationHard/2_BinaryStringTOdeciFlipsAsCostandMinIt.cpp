#include<bits/stdc++.h>
using namespace std;
//how to make graph for bit flipping with banned states
//nodes = all 20 bit binary strings = 2^20 = 1M nodes
//question is given a start string and end string and k banned strings
//space complexity is 2^20 * 20 edges at max
vector<int> g[(1<<20)+1]; // 2^20=1M nodes
bool ban[(1<<20)];

int getVal(string st){
    int val=0;
    for(int i=0;i<20;i++){
        if(st[i]=='1'){
            val|=(1<<i);
        }
    }
    return val;
}

void addEdge(int a, int b){
    if(!ban[a] && !ban[b]){
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
void solve(){
    string st,en;
    
    cin>>st>>en;
    int stval=getVal(st);
    int enval=getVal(en);
    
    int k;//num of strings banned
    cin>>k;
    for(int i=0;i<k;i++){
        string temp;
        cin>>temp;
        ban[getVal(temp)]=1;
    }
    
    for(int i=0;i<(1<<20);i++){
        for(int j=0;j<20;j++){
            addEdge(i,i^(1<<j));
        }
    }
    //run the graph algorithm
}

int main(){
    solve();
    return 0;
}