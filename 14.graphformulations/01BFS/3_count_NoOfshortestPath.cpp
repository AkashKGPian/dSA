#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
// input
// 6 6
// S.#...
// ..#...
// #.#...
// ....#.
// ####..
// F.....

//dont use vis array while counting no of shortest path in bfs 
//make it short yet optimumly correct

int n,m;
vector<string> arr;

using state = pair<int,int>;
#define f first 
#define s second 

vector<vector<int>> dist;
vector<vector<int>> numShortest_path;
vector<vector<state>> parent;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

bool is_inside(int nx, int ny){
    if(nx>=0&&nx<n && ny>=0&&ny<m)return 1;
    return 0;
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
    dist = vector<vector<int>>(n,vector<int>(m,INF));
    parent = vector<vector<state>>(n,vector<state>(m,{-1,-1}));
    numShortest_path = vector<vector<int>>(n,vector<int>(m,0));

    queue<state> q;
    dist[st.f][st.s]=0;
    numShortest_path[st.f][st.s]=1;
    q.push(st);

    while(!q.empty()){
        state curr=q.front();q.pop();
        // cout<<"Exploring "<<curr.f<<","<<curr.s<<"\n";

        //you explore every node exactly once
        //o(n+m) this below line only make this T.C;
        //same logic as that of dfs

        // print();
        
        for(int k=0;k<4;k++){
            int nx = curr.f+dx[k];
            int ny = curr.s+dy[k];
            
            if(is_inside(nx,ny) && arr[nx][ny]!='#'){
                if(dist[nx][ny]==INF){
                    // cout<<"found "<<neigh.f<<","<<neigh.s<<"\n";
                    dist[nx][ny]=dist[curr.f][curr.s]+1;
                    //curr me dist add karne par neigh ka dist aa raha hai now for this new neigh curr is the parent
                    numShortest_path[nx][ny]=numShortest_path[curr.f][curr.s];
    
                    //parent :  curr(new neigh's parent) ka loc
                    parent[nx][ny] = curr;
                    q.push({nx,ny});
                }else if(dist[nx][ny]==dist[curr.f][curr.s]+1){
                    numShortest_path[nx][ny]+=numShortest_path[curr.f][curr.s];
                }
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
            if(arr[i][j]=='S'){
                st={i,j};
            }else if(arr[i][j]=='F'){
                en={i,j};
            }
        }
    }
    bfs(st);
    cout<<dist[en.f][en.s]<<","<<numShortest_path[en.f][en.s]<<"\n";
    return 0;
}
