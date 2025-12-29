#include <bits/stdc++.h>
using namespace std;
//labyrinth cses

// input
// 5 8
// ########
// #.A#...#
// #.##..B#
// #......#
// ########

// ########
// #.A#...#
// #.##.#B#
// #......#
// ########

int n,m;//r,c
vector<string> arr;//2d arr
const int INF = 100;

using state = pair<int,int>;
#define f first 
#define s second 

vector<vector<int>> vis;
vector<vector<int>> dist;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

bool is_inside(int nx, int ny){
    if(nx>=0 && nx<n  &&  ny>=0 && ny<m)return 1;
    return 0;
}

//eligible neighbours apart form walls and obstabcles
vector<state> neighbours(state curr){
    vector<state> ans;
    for(int k=0;k<4;k++){
        int nx = curr.f+dx[k];
        int ny = curr.s+dy[k];
        if(is_inside(nx,ny) && arr[nx][ny]!='#'){
            ans.push_back({nx,ny});
        }
    }
    return ans;
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return ;
}

void bfs(state st){
    // == DO BFS ALGO..
    vis = vector<vector<int>>(n,vector<int>(m,0));//every coordinate in 2d matrix whether is it visited or not?
    dist = vector<vector<int>>(n,vector<int>(m,INF));//every coordinate has its dist value from start

    queue<state> q;
    //keeping the start dist as 0
    dist[st.f][st.s]=0;
    q.push(st);

    while(!q.empty()){
        state curr=q.front();q.pop();
        cout<<"Exploring "<<curr.f<<","<<curr.s<<"\n";

        //you explore every node exactly once
        //o(n+m) this below line only make this T.C;
        //same logic as that of dfs
        if(vis[curr.f][curr.s])continue;
        vis[curr.f][curr.s]=1;
        print();
        
        //pushing every eligible neighbour of curr in queue in dx,dy order
        for(auto neigh : neighbours(curr)){
            if(!vis[neigh.f][neigh.s]){
                cout<<"found "<<neigh.f<<","<<neigh.s<<"\n";
                dist[neigh.f][neigh.s]=dist[curr.f][curr.s]+1;
                q.push(neigh);//in the present input there is only one option (1,1) at first later it have more than one neigh
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    arr.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    state st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                st={i,j};
            }else if(arr[i][j]=='B'){
                en={i,j};
            }
        }
    }
    bfs(st);
    if(vis[en.f][en.s]){
        cout<<"YES\n";
        cout<<dist[en.f][en.s];//returns the shortest distance
    }else{
        cout<<"NO-there exist no path that reaches the end-B\n";
    }
    return 0;
}
