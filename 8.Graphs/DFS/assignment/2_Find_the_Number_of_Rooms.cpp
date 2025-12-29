#include <bits/stdc++.h>
using namespace std;
using state=pair<int,int>;
#define f first
#define s second
//count no. of rooms

int n,m;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

vector<vector<char>> orginalMap;
vector<vector<int>> vis;

queue<state> q;
int cnt;

bool is_inside(int nx,int ny){
    if((nx>=0 && nx<n) && (ny>=0 && ny<m))return 1;
    return 0;
}

vector<state> neighbours(state curr){
    vector<state> ans;
    for(int k=0;k<4;k++){
        int nx = curr.f + dx[k];
        int ny = curr.s + dy[k];
        if(is_inside(nx,ny) && orginalMap[nx][ny]=='.'){
            //ans push
            ans.push_back({nx,ny});
        }
    }
    //return statement
    return ans;
}

void bfs(state curr){
    q.push(curr);

    while(!q.empty()){
        state curr = q.front(); q.pop();

        if(vis[curr.f][curr.s])continue;
        vis[curr.f][curr.s]=1;

        for(auto neigh : neighbours(curr)){
            if(!vis[neigh.f][neigh.s]){
                q.push(neigh);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    orginalMap = vector<vector<char>> (n,vector<char> (m));
    vis = vector<vector<int>>(n, vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>orginalMap[i][j];
        }
    }
    //bfs(state st)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(orginalMap[i][j]=='.'){
                if(!vis[i][j]){
                    cnt++;
                    bfs(make_pair(i,j));
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
