#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
//labyrinth cses

// input
// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########

int n,m;
vector<string> arr;

using state = pair<int,int>;
#define f first 
#define s second 

vector<vector<int>> vis;
vector<vector<int>> dist;
vector<vector<state>> parent;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

bool is_inside(int nx, int ny){
    if(nx>=0&&nx<n && ny>=0&&ny<m)return 1;
    return 0;
}

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

// void print(){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<dist[i][j]<<"\t";
//         }
//         cout<<"\n";
//     }
//     cout<<"\n";
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<parent[i][j].f<<" "<<parent[i][j].s<<"\t";
//         }
//         cout<<"\n";
//     }
//     cout<<"\n";
//     return ;
// }

void bfs(state st){
    // == DO BFS ALGO..
    vis = vector<vector<int>>(n,vector<int>(m,0));
    dist = vector<vector<int>>(n,vector<int>(m,INF));
    parent = vector<vector<state>>(n,vector<state>(m,{-1,-1}));

    queue<state> q;
    dist[st.f][st.s]=0;
    q.push(st);

    while(!q.empty()){
        state curr=q.front();q.pop();
        // cout<<"Exploring "<<curr.f<<","<<curr.s<<"\n";

        //you explore every node exactly once
        //o(n+m) this below line only make this T.C;
        //same logic as that of dfs
        if(vis[curr.f][curr.s])continue;
        vis[curr.f][curr.s]=1;
        // print();

        for(auto neigh : neighbours(curr)){
            if(!vis[neigh.f][neigh.s]){
                // cout<<"found "<<neigh.f<<","<<neigh.s<<"\n";
                dist[neigh.f][neigh.s]=dist[curr.f][curr.s]+1;
                //curr me dist add karne par neigh ka dist aa raha hai now for this new neigh curr is the parent

                //parent :  curr(new neigh's parent) ka loc
                parent[neigh.f][neigh.s] = curr;
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
        cout<<dist[en.f][en.s]<<"\n";

        //printing path 
        vector<state> path;
        state cur=en;
        while(cur!=make_pair(-1,-1)){
            path.push_back(cur);
            cur=parent[cur.f][cur.s];
        }
        reverse(path.begin(),path.end());
        // for(auto v : path){
        //     cout<<v.f<<" "<<v.s<<"\n";
        // }
        string ansPathstr="";
        for(int i=1;i<path.size();i++){
            int chr=path[i].f-path[i-1].f;
            int chc=path[i].s-path[i-1].s;
            if(chr==1){
                ansPathstr+="D";
            }else if(chr==-1){
                ansPathstr+="U";
            }else if(chc==1){
                ansPathstr+="R";
            }else if(chc==-1){
                ansPathstr+="L";
            }else{
                assert(1==0);
            }
        }
        cout<<ansPathstr<<"\n";
    }else{
        cout<<"NO-there exist no path that reaches the end-B\n";
    }
    return 0;
}
