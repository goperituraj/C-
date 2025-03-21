// Step-by-step guide:
// 1. Read the problem statement carefully.
// 2. Visualize and dry-run examples.
// 3. Implement the solution here.
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve()
{

    ll n;
    cin >> n;
    vector<ll> ans(n, -1);
    map<int, vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {

            if (s[j] == '1')
            {
                adj[i + 1].push_back(j + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ll cnt = 0;
        for (auto it : adj[i])
        {
            if (it > i)
                cnt++;
        }
        ll j = n - 1;
        for (j = n - 1; j >= 0 && cnt; j--)
            if (ans[j] == -1)
                cnt--;
        while (j >= 0 && ans[j] != -1)
            j--;
        ans[j] = i;
    }
    for (auto it : ans)
    {
        cout << it << " ";
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