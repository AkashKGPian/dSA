#include<bits/stdc++.h>
using namespace std;

using state=pair<int,int>;
#define f first
#define s second
const int INF = 1e9;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int n,m;
vector<string> arr;
vector<vector<int>> vis;
vector<vector<int>> dist;

bool isinside(int nx, int ny){
    if( (nx>=0) && (nx<n) && (ny>=0) && (ny<m) ) return 1;
    else return 0;
}

void bfs01(state st){
    vis = vector<vector<int>>(n,vector<int>(m,0));
    dist = vector<vector<int>>(n,vector<int>(m,INF));
    
    dist[st.f][st.s]=0;
    deque<state> dq;
    dq.push_back(st);
    
    while(!dq.empty()){
        state curr = dq.front(); dq.pop_front();
        if(vis[curr.f][curr.s] == 1) continue;
        vis[curr.f][curr.s] = 1;
        
        for(int k=0;k<4;k++){
            int nx = curr.f + dx[k];
            int ny = curr.s + dy[k];
            
            if(isinside(nx,ny)){
                int edge = (arr[nx][ny]=='#') ? 1 : 0;
                if(dist[nx][ny] > dist[curr.f][curr.s]+edge){
                    dist[nx][ny] = dist[curr.f][curr.s]+edge;
                    if(edge==0){ 
                        dq.push_front({nx,ny});
                    }else{
                        dq.push_back({nx,ny});
                    }
                }
            }
        }
    }
}



int main(){
    cin>>n>>m;
    arr.resize(n);
    
    state st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S') st = {i,j};
            else if(arr[i][j]=='E') en = {i,j};
        }
    }
    
    bfs01(st);
    cout<<dist[en.f][en.s]<<"\n";//here dist stores the cost ie the cost of breaking walls
    return 0;
}