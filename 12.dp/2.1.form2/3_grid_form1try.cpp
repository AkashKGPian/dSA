#include <bits/stdc++.h>
using namespace std;
#define state pair<int,int>
#define f first
#define s second
// 3
// 1 2 3
// 4 5 6
// 7 8 9


int n;
int arr[1010][1010];
int sum,ans;

int dx[]={1,0};
int dy[]={0,1};


bool is_inside(int nx, int ny){
    if(nx>=0 && nx<n && ny>=0 && ny<n)return 1;
    else return 0;
}

vector<state> neighbours(state curr){
        vector<state> ans;
        for(int i=0;i<2;i++){
            int nx = curr.f + dx[i]; // moved nx, ny definition here
            int ny = curr.s + dy[i]; // moved nx, ny definition here
            if(is_inside(nx,ny)){ // <-- this must be inside the loop, otherwise nx,ny are out of scope
                ans.push_back({nx, ny}); // <-- must push a pair like {nx, ny}, not two separate ints
            }
        }
        return ans;
    }

// changed return type from int to void, because function does not return anything
void rec(int level, int stx, int sty){
    //pruning
    //base case
    // instead of checking level == 2*n, check coordinates to avoid off-by-one
    if(stx==n-1 && sty==n-1){
        ans=max(ans,sum);
        return;
    }
    //choices
    state curr = make_pair(stx, sty);
    for(auto neigh : neighbours(curr)){
        sum+=arr[neigh.f][neigh.s];
        rec(level+1,neigh.f,neigh.s);
        sum-=arr[neigh.f][neigh.s];
    }
    //check
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ // <-- was i<n instead of j<n
            cin>>arr[i][j];
        }
    }
    sum = arr[0][0]; // <-- must initialize sum with starting cell value
    rec(0,0,0);
    cout<<ans;
    return 0;
}
