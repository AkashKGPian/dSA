#include <bits/stdc++.h>
using namespace std;

#define state pair<int,int>
#define f first
#define s second
const int INF = 1e9;
class Solution {
public:
    int n,m;
    vector<vector<int>> grid; 
    // vector<vector<int>> vis; 
    queue<state> q;
    int fresh=0,mins=0;

    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};

    bool isInside(int nx, int ny){
        if(nx>=0 && nx<n && ny>=0 && ny<m) return 1;
        else return 0;
    }
    vector<state> neighbours(state node){
        vector<state> ans;
        for(int k=0;k<4;k++){
            int nx=node.f+dx[k];
            int ny=node.s+dy[k];
            ans.push_back({nx,ny});
        }
        return ans;
    }

    int bfs(){
        // vis = vector<vector<int>>(n,vector<int>(m,0));

        while(!q.empty()){
            int sz=q.size();//for every invarient size/same dist elem do min++
            int isRottenThisMin=0;

            while(sz--){
                state curr=q.front(); q.pop();
                // if(vis[curr.f][curr.s])continue;
                // vis[curr.f][curr.s]=1;

                for(auto neigh:neighbours(curr)){
                    if(isInside(neigh.f,neigh.s)&&grid[neigh.f][neigh.s]==1){
                        grid[neigh.f][neigh.s] = 2; 
                        fresh--;
                        isRottenThisMin=1;
                        q.push(neigh);
                    }
                }
            }
            if(isRottenThisMin)mins++;
        }
        return (fresh==0)? mins:-1;
    }

    int orangesRotting(vector<vector<int>>& input) {
        grid=input;
        n=input.size();
        m=input[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(input[i][j]==2){
                    q.push({i,j});
                }else if(input[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans = bfs();
        return ans;
    }
};