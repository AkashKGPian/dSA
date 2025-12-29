#include<bits/stdc++.h>
using namespace std;

//lis optimized 
//logic == space optimized by taking last and length

// 10
// 1 5 7 10 9 6 7 9 2 3

int main(){
    //given n, arr
    int n;
    cin>>n;
    int arr[1010];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //find lis
    vector<int> lis;
    vector<int> insertedAt;
    insertedAt.resize(n);
    //saving last smallest elem at len i;
    for(int i=0;i<n;i++){
        if(lis.empty()||lis.back()<arr[i]){
            lis.push_back(arr[i]);//storing smallest last value
            insertedAt[i]=lis.size()-1;//
        }else{
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it = arr[i];
            insertedAt[i]=it-lis.begin();//
        }
        cout<<i<<" : ";
        for(auto v : lis){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    
    // for(int i=0;i<n;i++){
    //     cout<<insertedAt[i]<<" ";
    // }
    // cout<<"\n"; taking the first elm of the repeating shit
    
    vector<int> final_lis;
    int curlen=lis.size()-1;//or any given len asked in the question
    for(int i=n-1;i>=0;i--){
        if(insertedAt[i]==curlen){
            final_lis.push_back(arr[i]);
            curlen--;
        }
    }
    reverse(final_lis.begin(), final_lis.end());
    for(auto v :final_lis){
        cout<<v<<" ";
    }
    return 0;
}