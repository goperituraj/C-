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
    vector<vector<ll>> v;
    set<ll> st;

    for (int i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        vector<ll> m(k);

        for (int j = 0; j < k; j++)
        {
            ll x;
            cin >> x;
            m[j] = x;
            st.insert(x);
        }
        v.push_back(m);
    }

    ll ans = 0, tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot += v[i].size();
    }

    for (int k = 1; k <= 50; k++)
    {
        if (st.find(k) == st.end())
            continue;

        vector<ll> idx;
        for (int i = 0; i < n; i++)
        {
            for (int j : v[i])
            {
                if (j == k)
                {
                    idx.push_back(i);
                    break;
                }
            }
        }

        set<ll> excluded_indices(idx.begin(), idx.end());
        set<ll> unique_elements;

        for (int i = 0; i < n; i++)
        {
            if (excluded_indices.find(i) == excluded_indices.end())
            {
                for (ll x : v[i])
                {
                    unique_elements.insert(x);
                }
            }
        }

        ans = max(ans, (ll)unique_elements.size());
    }
    cout << ans << endl;
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
