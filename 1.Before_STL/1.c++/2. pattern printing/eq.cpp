#include <bits/stdc++.h>
using namespace std;

void func(int i, int j, int r, int c, int k) {
    // Diamond logic: Adjust boundaries for `*`
    if (i + j >= k && i + j <= r - 1 + k && j - i <= k && i - j <= k) {
        cout << "*";
    } else {
        cout << " ";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r, c;
    cin >> r >> c;

    // Ensure r and c are odd for a symmetric diamond
    if (r % 2 == 0 || c % 2 == 0) {
        cout << "Please provide odd values for r and c to create a symmetric diamond.\n";
        return 0;
    }

    int k = r / 2; // Middle row/column index
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            func(i, j, r, c, k); // Call the function for each position
        }
        cout << "\n";
    }

    return 0;
}
