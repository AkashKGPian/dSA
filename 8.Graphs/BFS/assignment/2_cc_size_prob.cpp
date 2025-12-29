#include <bits/stdc++.h>
using namespace std;
using state = pair<int,int>;
#define f first 
#define s second 

int n,m;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

vector<vector<int>> arr;
vector<vector<int>> vis;

vector<vector<int>> cc_id;
unordered_map<int,int> cc_id_size;
queue<state> q;

bool is_inside(int nx,int ny){
    if((nx>=0 && nx<n) && (ny>=0 && ny<m))return 1;
    return 0;
}

vector<state> neighbours(state curr){
    vector<state> ans;
    for(int k=0;k<4;k++){
        int nx = curr.f + dx[k];
        int ny = curr.s + dy[k];
        if(is_inside(nx,ny) && arr[nx][ny]==0){
            ans.push_back(make_pair(nx,ny));
        }
    }
    return ans;
}

void bfs(state st,int id){
    q.push(st);
    cc_id[st.f][st.s]=id;
    cc_id_size[id]++;
    while(!q.empty()){
        state curr = q.front(); q.pop();
        // if(vis[curr.f][curr.s])continue;// u cant continue cuz u need to iter
        vis[curr.f][curr.s]=1;

        for(auto neigh : neighbours(curr)){
            if(!vis[neigh.f][neigh.s]){
                vis[neigh.f][neigh.s] = 1;//
                cc_id[neigh.f][neigh.s] = id;//
                cc_id_size[id]++;
                q.push(neigh);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vis = vector<vector<int>>(n, vector<int>(m,0));
        cc_id = vector<vector<int>>(n, vector<int>(m,0));
        arr = vector<vector<int>>(n,vector<int> (m,0));
        cc_id_size.clear();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        int id=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    if(!vis[i][j]){
                        id++;
                        bfs({i,j},id);
                    }
                }
            }
        }
        int temp = cc_id.size();
        while(temp--){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int cc_idx = cc_id[i][j];
                    if(cc_id_size[cc_idx]>1){
                        arr[i][j]=cc_id_size[cc_idx];
                    }
                }
            }
        }
       //q reset
        while(!q.empty()){
            q.pop();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
