#include <bits/stdc++.h>
using namespace std;

// iterating on solution/index
//solution build karne ka hota hai to permutation ho jata hia vo

int n,k;
vector<int> arr;//taking in the given list

// solution data sturc. 
vector<int>taken;//visited array
vector<int>cur;//making the solution vector

void rec(int level){
    // cout<<level<<" : ";
    // for(auto v : cur){
    //         cout<<v<<" ";
    //     }
    //     cout<<"\n";
    if(level==k){
        for(auto v : cur){
            cout<<v<<" ";
        }
        cout<<"\n";
        return ;
    }

    //recursive part
    for(int i=0;i<n;i++){
        if(!taken[i]){
            cur.push_back(arr[i]);
            taken[i]=1;
            rec(level+1);
            taken[i]=0;
            cur.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    taken.resize(n,0);
    arr.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\n";
    rec(0);
    return 0;
}
//############################
// test case example for stack vizualization

// #include<bits/stdc++.h>
// using namespace std;

// int arr[3];
// vector<int> sol;
// int taken[3];//visited array

// void perm(int level){
//     if(level==2){
//         for(int i=0;i<2;i++)cout<<sol[i]<<" ";cout<<"\n";
//         return;
//     }
//     //recursive case
//     for(int i=0;i<3;i++){
//         if(!taken[i]){
//             sol.push_back(arr[i]);
//             taken[i]=1;
//             perm(level+1);
//             taken[i]=0;
//             sol.pop_back();
//         }
//     }
// }

// int main(){
//     arr[0]=2,arr[1]=5,arr[2]=7;
//     perm(0);
//     return 0;
// }