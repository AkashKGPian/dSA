#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define state pair<ii,int> //pair(cordinates, checkif-2present)
#define lli long long
#define F first
#define S second
#define MP make_pair
const int INF = 1e9;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int n,m;
int arr[1010][1010];
vector<vector<vector<int>>> vis;
vector<vector<vector<lli>>> dist;
vector<vector<vector<state>>> parent;

vector<ii> sc, mid, en;

int isInside(int nx, int ny){
    if(nx>=0 && nx<n && ny>=0 && ny<m) return 1;
    else return 0;
}

void dijktra(ii sc){
    vis = vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(2,0)));
    dist = vector<vector<vector<lli>>>(n,vector<vector<lli>>(m,vector<lli>(2,INF)));
    parent = vector<vector<vector<state>>>(n,vector<vector<state>> (m, vector<state>(2,{{-1,-1}, -1})));
    
    dist[sc.F][sc.S][0]=0; // dist(cordn)(0) not seen -2 till now ; dist(cordn)(1) seen -2 
    priority_queue<pair<lli, state>> pq; //dist, state
    pq.push( MP(-0,MP(sc,0) ) );
    while(!pq.empty()){
        pair<lli, state> temp = pq.top(); pq.pop();
        lli currdist = -temp.F;//taking out ve+ dist
        state curr = temp.S;
        
        if(vis[curr.F.F][curr.F.S][curr.S])continue;
        vis[curr.F.F][curr.F.S][curr.S]=1;
        
        for(int k=0;k<4;k++){
            int nx = curr.F.F + dx[k];
            int ny = curr.F.S + dy[k];
            
            if(isInside(nx,ny)){
                int newFlag = curr.S | (arr[nx][ny]==-2);
                if( dist[nx][ny][newFlag] > currdist + max(0,arr[nx][ny]) ){
                    dist[nx][ny][newFlag] = currdist + max(0,arr[nx][ny]);
                    parent[nx][ny][newFlag] = curr;
                    pq.push(MP(-dist[nx][ny][newFlag],MP(MP(nx,ny),newFlag)));
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==-1){
                sc.push_back(MP(i,j));
            }else if(arr[i][j]==-2){
                mid.push_back(MP(i,j));
            }else if(arr[i][j]==-3){//pair of coordinates
                en.push_back(MP(i,j));
            }
        }
    }
    dijktra(sc[0]);// coordinates
    lli ans = 1e9;
    for( auto enpos:en ){
        cout<<ans<<"\n";
        ans = min(ans, dist[enpos.F][enpos.S][1]);
    }
    cout<<ans<<"\n";
    
    state curr = {{3,2},1};
    while(curr != state({{-1,-1},-1})){
        cout<< curr.F.F <<","<< curr.F.S<<"\n";
        curr = parent[curr.F.F][curr.F.S][curr.S];
    }
    return 0;
}