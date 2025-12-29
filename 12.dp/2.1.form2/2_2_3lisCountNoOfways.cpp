#include<bits/stdc++.h>
using namespace std;

// Given an integer array 
// arr, output the number of longest increasing subsequences. The sequence has to be strictly increasing. //test case below
// input
// 1
// 5
// 1 3 5 4 7 output // 2

const int MOD = 1000000007;

int arr[1010];

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        vector<int> len(n, 1);   // length of LIS ending at i
        vector<int> ways(n, 1);  // number of LIS ending at i

        int bestLen = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    if(len[j] + 1 > len[i]){
                        len[i] = len[j] + 1;
                        ways[i] = ways[j];  
                    }
                    else if(len[j] + 1 == len[i]){
                        ways[i] = (ways[i] + ways[j]) % MOD;
                    }
                }
            }
            bestLen = max(bestLen, len[i]);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(len[i] == bestLen){
                ans = (ans + ways[i]) % MOD;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}