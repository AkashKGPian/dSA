#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;// directed
vector<vector<int>> par; //storing parent for binary lifting 2^i
vector<int> roots;
vector<int> depth;
int PthAnc;
int findPthAnc;

int m;

void dfs(int nn, int dd){
    depth[nn]=dd;
    
    for(int i=1; i<20; i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
    }
    for(auto v:g[nn]){
        if(v==par[nn][0]) continue;//not neccessary
        dfs(v,dd+1);
    }
}

int main() {
    cin >> n;
    g.resize(n+1);
    par.assign(n+1,vector<int>(20));
    depth.resize(n+1);
    
    for(int i=1; i<=n; i++){
        cin>>par[i][0];
    }
    for(int i=1; i<=n; i++){
        if (par[i][0]==0){
            roots.push_back(i);      // root of a tree
        }else{
            g[par[i][0]].push_back(i); // edge parent -> child
        }
    }
    for(int r : roots){
        dfs(r, 0);
    }
    
    cin>>m;
    while(m--){
        int v,p;
        cin>>v>>p;
        PthAnc=v;
        for(int i=19;i>=0;i--){
            if(p&(1<<i)){
                PthAnc = par[PthAnc][i];
            }
        }
        if(PthAnc == 0){
            cout << 0 << " ";
            continue;
        }

        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i==v)continue;
            if(depth[v]==depth[i]){
                findPthAnc=i;
                for(int i=19;i>=0;i--){
                    if(p&(1<<i)){
                        findPthAnc = par[findPthAnc][i];
                    }
                }
                if(findPthAnc==PthAnc) cnt++;
            }
        }
        cout<<cnt<<" ";
    }
    return 0;
}
