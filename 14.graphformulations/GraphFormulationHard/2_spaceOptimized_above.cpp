#include <bits/stdc++.h>
using namespace std;

bool ban[1<<20];
bool vis[1<<20];

int getVal(string st){
    int val=0;
    for(int i=0;i<20;i++){
        if(st[i]=='1') val |= (1<<i);
    }
    return val;
}

int bfs(int st, int en){
    if(ban[st] || ban[en]) return -1;

    queue<pair<int,int>> q;
    q.push({st,0});
    vis[st]=1;

    while(!q.empty()){
        auto [u,dist] = q.front(); q.pop();

        if(u==en) return dist;

        for(int j=0;j<20;j++){
            int v = u ^ (1<<j); // flip bit

            if(!ban[v] && !vis[v]){
                vis[v]=1;
                q.push({v,dist+1});
            }
        }
    }
    return -1;
}

int main(){
    string st,en;
    cin>>st>>en;

    int stval=getVal(st);
    int enval=getVal(en);

    int k;
    cin>>k;
    while(k--){
        string temp;
        cin>>temp;
        ban[getVal(temp)]=1;
    }

    cout<<bfs(stval,enval);
}
