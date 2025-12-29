// #include <bits/stdc++.h>
// using namespace std;

// void replace(vector<int> &v, int b, int c){
//     for(auto it=v.begin(); it!=v.end(); ++it){
//         if((*it) == b){
//             (*it) = c;
//         }
//     }
//     return ;
// }

// int sum_t(vector<int> &v){
//     int sum=0;
//     for(auto it=v.begin(); it!=v.end(); ++it){
//         sum+=(*it);
//     }
//     return sum;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin>>n;
//     vector<int>v;
//     for(int i=0;i<n;i++){
//         int r;
//         cin>>r;
//         v.push_back(r);
//     }

//     int q;
//     cin>>q;
//     for(int i=0;i<q;i++){
//         int b,c;
//         cin>>b>>c;
//         replace(v,b,c);
//         int sum = sum_t(v);
//         cout<<sum<<"\n";
//     }
//     return 0;
// }
