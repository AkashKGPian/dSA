#include <bits/stdc++.h>
using namespace std;

struct monotone_dequeue{
    deque<int> dq;
    void add(int x){
        while(!dq.empty() && dq.back()>x){//o(k) - > armotized t.c is //o(1)
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x){//o(1)
        if(dq.front()==x){
            dq.pop_front();
        }
    }
    int get_min(){//o(1)
        return dq.front();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    monotone_dequeue mdq;
    for(int i=0;i<n;i++){//o(k*n) but the armotized T.C is //o(n)
        mdq.add(arr[i]);//o(k) //Armotized TC //o(1)
        if(i-k>=0) mdq.remove(arr[i-k]);//o(1)
        if(i>=(k-1)) cout<<mdq.get_min()<<"\n";//ek particular i ke badd se print end tak karna hai ie k-1//0 indexing
    }
    return 0;
}
