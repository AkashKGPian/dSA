#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define f first
#define s second
typedef pair<int,int> state;

int n,m;
vector<string> arr;

int dist[1001][1001];
int distPer[1001][1001];
state par[1001][1001];
int vis[1001][1001];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool isInside(int nx, int ny){
    if(nx>=0 && nx<n && ny>=0 && ny<m) return 1;
    return 0;
}

void bfsP(){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            distPer[i][j]=1e9;
        }
    }
    queue<state> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                distPer[i][j]=0;
                par[i][j]= {-1,-1};
                q.push(MP(i,j));
            }
        }
    }
    while(!q.empty()){
        state curr = q.front(); q.pop();
        
        if(vis[curr.f][curr.s])continue;
        vis[curr.f][curr.s]=1;
        for(int k=0;k<4;k++){
            int nx=curr.f + dx[k];
            int ny=curr.s + dy[k];
            
            if(isInside(nx,ny)){
                if(arr[nx][ny]!='#' && distPer[nx][ny]>distPer[curr.f][curr.s]+1){
                    distPer[nx][ny]=distPer[curr.f][curr.s]+1;
                    par[nx][ny]=curr;
                    q.push(MP(nx,ny));
                }
            }
        }
    }
}

void bfsM(){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=1e9;
        }
    }
    queue<state> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='M'){
                dist[i][j]=0;
                q.push(MP(i,j));
            }
        }
    }
    while(!q.empty()){
        state curr = q.front(); q.pop();
        if(vis[curr.f][curr.s])continue;
        vis[curr.f][curr.s]=1;
        for(int k=0;k<4;k++){
            int nx=curr.f + dx[k];
            int ny=curr.s + dy[k];
            
            if(isInside(nx,ny)){
                if(arr[nx][ny]!='#' && dist[nx][ny]>dist[curr.f][curr.s]+1){
                    dist[nx][ny]=dist[curr.f][curr.s]+1;
                    q.push(MP(nx,ny));
                }
            }
        }
    }
}


int main(){
    cin>>n>>m;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bfsM();
    bfsP();
    int checkPossible=0;
    state SafeExit;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(arr[i][j]!='#' && arr[i][j]!='M'){
                    if(distPer[i][j] < dist[i][j]){
                        checkPossible=1;
                        SafeExit={i,j};
                        break;
                    }
                }
            }
        }
    }
    
    
    if(checkPossible){
        cout<<"YES\n";
        cout<<distPer[SafeExit.f][SafeExit.s]<<"\n";
        //--
        vector<char> path;
        state cur = SafeExit;
        
        while(par[cur.f][cur.s] != MP(-1,-1)){
            state p = par[cur.f][cur.s];
        
            if(p.f == cur.f - 1) path.push_back('D');
            else if(p.f == cur.f + 1) path.push_back('U');
            else if(p.s == cur.s - 1) path.push_back('R');
            else if(p.s == cur.s + 1) path.push_back('L');
        
            cur = p;
        }
        reverse(path.begin(), path.end());
        
        for(char c : path) cout << c;
        cout << "\n";
    }else{
        cout<<"NO\n";
    }
    
    
    return 0;
}