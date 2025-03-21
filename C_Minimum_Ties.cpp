#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    ll n;
    cin >> n;
    ll matches = (n * (n - 1)) / 2;
    ll w = matches / n;
    vector<int> result(matches, 0);
    vector<int> wins(n + 1, 0);
    vector<pair<int, int>> pairs;

    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            pairs.push_back({i, j});
        }
    }

    for (auto it : pairs)
    {
        int i = it.first, j = it.second;
        if (wins[i] < w)
        {
            result[idx] = 1;
            wins[i]++;
        }
        idx++;
    }

    idx = 0;
    for (auto it : pairs)
    {
        int i = it.first, j = it.second;
        if (result[idx] == 0)
        {
            if (wins[j] < w)
            {
                result[idx] = -1;
                wins[j]++;
            }
        }
        idx++;
    }

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}