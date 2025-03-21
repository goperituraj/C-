#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> grid(n, vector<ll>(m));
        ll maxC = n * m;
        set<ll> st;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                st.insert(grid[i][j]);
            }
        }
        vector<ll> v(maxC + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int col = grid[i][j];
                if (j + 1 < m)
                {
                    if (grid[i][j + 1] == col)
                    {
                        v[col] = 1;
                    }
                }
                if (i + 1 < n)
                {
                    if (grid[i + 1][j] == col)
                    {
                        v[col] = 1;
                    }
                }
            }
        }
        ll ans = 0;
        bool f = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
            {
                ans += 2;
                f = true;
            }
            else if (st.find(i) != st.end())
            {
                st.erase(i);
                ans++;
            }
        }
        if (f)
            ans -= 2;
        else
            ans--;
        cout << ans << endl;
    }
    return 0;
}
