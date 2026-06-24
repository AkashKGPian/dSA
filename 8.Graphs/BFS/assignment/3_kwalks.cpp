#include <bits/stdc++.h>
using namespace std;
using state = pair<int,int>;
const int INF = 1e9;
#define f first 
#define s second 

//defining ds
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};

// vector<vector<int>> arr;
vector<vector<int>> vis;
vector<vector<int>> dist;

bool is_inside(int nx,int ny,int N){
    if((nx>=0 && nx<N) && (ny>=0 && ny<N))return 1;
    return 0;
}

vector<state> neighbours(state curr,int N){
    vector<state> ans;
    for(int k=0;k<8;k++){
        int nx = curr.f + dx[k];
        int ny = curr.s + dy[k];
        if(is_inside(nx,ny,N)){
            ans.push_back({nx,ny});
        }
    }
    return ans;
}

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy){
    if (Sx == Fx && Sy == Fy) return 0;
    queue<state> q;
    // arr = vector<vector<int>> (N,vector<int>(N));
    vis = vector<vector<int>> (N,vector<int> (N,0));
    dist = vector<vector<int>> (N,vector<int> (N,INF));
    q.push({Sx,Sy});
    dist[Sx][Sy]=0;

    while(!q.empty()){
        state curr = q.front(); q.pop();
        if(vis[curr.f][curr.s])continue;
        vis[curr.f][curr.s]=1;

        for(auto neigh : neighbours(curr,N)){
            if(!vis[neigh.f][neigh.s]){
                dist[neigh.f][neigh.s] = dist[curr.f][curr.s] + 1;
                q.push(neigh);
            }
            if((neigh.f==Fx) && (neigh.s==Fy)){
                return dist[neigh.f][neigh.s];
            }
        }
    }
    if(!vis[Fx][Fy]){
        return -1;
    }
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--){
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx-1, Sy-1, Fx-1, Fy-1) << "\n";
	}
}
