#include<bits/stdc++.h>
using namespace std;

#define int long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cout << "Enter n : ";
    cin >> n;
    int arr[n];
    int max_el = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        max_el = max(max_el,arr[i]);
    }
    //freq_Arr
    //creating a freq array initiallized to zero
    int freq_arr[max_el + 1]{};
    //if the arr contains ve- no. then 
    for(int i=0; i<n ; i++){//traverse the array and store the freq count from 0 to n
        //condtion to check for negative 
        if(arr[i]>=0){
            //freq++
            freq_arr[arr[i]]++;
        }
    }
    int k=0;
    for(int i=0;i<=max_el;i++){
        for(int j=0;j<freq_arr[i];j++){
            if(freq_arr[i]==0 || i==0)break;
            else{
                arr[k]=i;
                k++;
            }
        }
    }
    return 0;
}