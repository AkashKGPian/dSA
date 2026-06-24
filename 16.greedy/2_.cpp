#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define vpi vector<pi>
#define pb push_back
#define all(a) (a).begin(), (a).end()
const int mod = 1e9 + 7;

bool cmp(pi a, pi b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vpi v(n);
    vector<vi> vm(m);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].first > m)
            continue;
        vm[m - v[i].first].pb(v[i].second);
    }
    multiset<int> ms;
    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        for (auto x : vm[i])
        {
            ms.insert(x);
        }
        if (ms.size() > 0)
        {
            ans += *ms.rbegin();
            ms.erase(prev(ms.end()));
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}