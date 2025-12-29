#include<bits/stdc++.h>
using namespace std;

//state = state(old),int 
using state=pair<pair<int,int>,int>;
#define f first
#define s second
const int INF = 1e9;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


int n,m,k;
vector<string> arr;
vector<vector<vector<int>>> vis;
vector<vector<vector<int>>> dist;
//now vis and dist are 3d vector where i,j = coordinates and k is the #ofwallsBroken
//simply [curr.f.f][curr.f.s] and k=[curr.s] 

bool isinside(int nx, int ny){
    if( (nx>=0) && (nx<n) && (ny>=0) && (ny<m) ) return 1;
    else return 0;
}

void bfs(pair<int,int> st){
    //assigning
    vis = vector<vector<vector<int>>>
                        (n,vector<vector<int>>
                            (m,vector<int>
                                (k+1,0)//k+1 have k as an accessible arr index as restriction wallbroken >=k
                            )
                        );
    dist = vector<vector<vector<int>>>
                                (n,vector<vector<int>>
                                    (m,vector<int>
                                        (k+1,INF)
                                    )
                                );
    //minimizing the steps => cost of every step = same = 1; ==> simple bfs
    
    dist[st.f][st.s][0]=0;
    //since simple bfs
    queue<state> dq;
    dq.push({st,0});
    
    while(!dq.empty()){
        state curr = dq.front(); dq.pop();
        if(vis[curr.f.f][curr.f.s][curr.s] == 1) continue;
        vis[curr.f.f][curr.f.s][curr.s] = 1;
        
        for(int dirc=0;dirc<4;dirc++){
            int nx = curr.f.f + dx[dirc];
            int ny = curr.f.s + dy[dirc];
            
            if(isinside(nx,ny)){
                int nw = curr.s + ((arr[nx][ny]=='#')? 1:0);
                if(nw>k) continue;//cannot break more than k walls
                if(dist[nx][ny][nw] > dist[curr.f.f][curr.f.s][curr.s]+1){
                    dist[nx][ny][nw] = dist[curr.f.f][curr.f.s][curr.s]+1;
                    dq.push({{nx,ny}, nw});
                }
            }
        }
    }
}



int main(){
    cin>>n>>m>>k;
    arr.resize(n);
    
    pair<int,int> st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S') st = {i,j};
            else if(arr[i][j]=='E') en = {i,j};
        }
    }
    
    bfs(st);//at starting point 0 walls broken
    int ans=INF;
    for(int x=0;x<=n*m;x++){
        // ans = min(ans,dist[en.f][en.s][x]);
        cout<<x<<" : "<<dist[en.f][en.s][x]<<"\n";//here dist stores the cost ie the cost of breaking walls
    }
    // cout<<"min no. of steps req if we can break<=k walls : "<<ans;
    return 0;
}