#include <bits/stdc++.h>
using namespace std;

int n,k;
pair<int,int> arr[100010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second; //s[i] and e[i]
    }
    sort(arr,arr+n);
    reverse(arr,arr+n);

    priority_queue< int, vector<int>, greater<int> > pq; //min at the end/top
    int top_k_sum=0;
    int best_team_score = 0;

    for(int i=0;i<n;i++){
        pq.push(arr[i].second);
        top_k_sum+=arr[i].second;
        if(pq.size()>k){
            int x=pq.top(); pq.pop();
            top_k_sum -= x;
        }

        if(pq.size()==k){
            best_team_score=max(best_team_score, arr[i].first*top_k_sum);
        }
    }
    cout<<best_team_score<<"\n";
    return 0;
}
