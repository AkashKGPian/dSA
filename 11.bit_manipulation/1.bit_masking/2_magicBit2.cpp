#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    bitset<64>x;
    while(t--){
        int n;
        cin>>n;
        x = n;

        cout<<x.to_string()<<"\n";
        
        if(n==0)cout<<-1<<"\n";
        else {
            //    msb cout 
            int msb = -1;
            for(int i = 63; i >= 0; i--){
                if(n & (1LL << i)){
                    msb = i;
                    break;
                }
            }
            cout << msb << "\n";
        }
        //3 rm
        int lsb = -1;
        for(int i = 0; i < 64; i++){
            if(n & (1LL << i)){
                lsb = i;
                break;
            }
        }
        cout << lsb << "\n";

        //  Check if n is power of 2 and n > 1
        if (n > 1 && (n & (n - 1)) == 0)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";

        //  Largest power of 2 that divides n
        if (n == 0)
            cout << -1 << "\n";
        else
            cout << (n & -n) << "\n";  // Trick: n & (-n) gives lowest set bit

        //  Smallest power of 2 ≥ n, with k > 0
        if (n <= 1) {
            cout << 2 << "\n";
        } else {
            uint64_t res = 1;
            while (res < n) res <<= 1;
            cout << res << "\n";
        }
    }
    
    return 0;
}