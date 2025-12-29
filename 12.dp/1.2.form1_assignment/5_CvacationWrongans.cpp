#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100100],b[100100],c[100100];
int dp[100100][3];


signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];
    //dp[i][0]= should be sum of max other two dp[i-1][1] and dp[i-1][2] +a[i] > then induction
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b[i];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c[i];
    }
    cout<<max({ dp[n-1][0], dp[n-1][1], dp[n-1][2] })<<"\n";
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define state pair<int,int> // (happiness, label)
// #define f first
// #define s second

// int n;
// int a[100010], b[100010], c[100010];
// int sumPoints = 0;

// // Return the label of the activity to choose (0=A, 1=B, 2=C)
// int chooseActivity(state max1, state max2, int prev) {
//     if (prev != max1.s) {
//         return max1.s;
//     } else {
//         return max2.s; // prev was max1, so take second best
//     }
// }

// void rec(int day, int prev) {
//     if (day == n) return;

//     // Find top 2 activities for this day
//     state max1 = {a[day], 0};
//     state max2 = {b[day], 1};

//     // Make sure max1 is the largest
//     if (max2.f > max1.f) swap(max1, max2);

//     // Check C
//     if (c[day] > max1.f) {
//         max2 = max1;
//         max1 = {c[day], 2};
//     } else if (c[day] > max2.f) {
//         max2 = {c[day], 2};
//     }

//     // Choose based on prev
//     int choice = chooseActivity(max1, max2, prev);
//     if (choice == 0) sumPoints += a[day];
//     else if (choice == 1) sumPoints += b[day];
//     else sumPoints += c[day];

//     // Recurse for next day
//     rec(day + 1, choice);
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i] >> b[i] >> c[i];
//     }

//     rec(0, -1);
//     cout << sumPoints << "\n";
//     return 0;
// }
