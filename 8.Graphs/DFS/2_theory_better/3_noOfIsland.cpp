#include <bits/stdc++.h>
using namespace std;

#define state pair<int,int>
#define F first 
#define S second
class Solution{
    public:
    int n,m;
    vector<vector<char>> g;
    vector<vector<int>> vis;

    int dx[8]={1,1,0,-1,-1,-1,0,1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};

    bool isInside(int nx, int ny){
        if(nx>=0 && nx<n && ny>=0 && ny<m) return 1;
        else return 0;
    }

    void dfs(state nn){
        vis[nn.F][nn.S]=1;
        for(int k=0;k<8;k++){
            int nx=nn.F+dx[k];
            int ny=nn.S+dy[k];
            if(isInside(nx, ny) && !vis[nx][ny] && g[nx][ny] == '1'){
                dfs({nx,ny});
            }
        }
    }

    int numIslands(vector<vector<char>> &grid){
        g=grid;
        n=grid.size();
        m=grid[0].size();
        vis.assign(n,vector<int>(m,0));
        
        int cc_cmps=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&& g[i][j] == '1'){
                    cc_cmps++;
                    dfs({i,j});
                }
            }
        }
        return cc_cmps;
    }
};
