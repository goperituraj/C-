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
    vector<ll> v(n);
    set<ll> st;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v[i] = x;
        st.insert(x);
    }
    set<ll> st1;
    for (int i = 1; i <= n; i++)
    {
        if (st.find(i) == st.end())
        {
            st1.insert(i);
        }
    }
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (st.find(v[i]) != st.end())
        {
            ans[i] = v[i];
            st.erase(v[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == -1)
        {
            for (auto it : st1)
            {
                ans[i] = it;
                st1.erase(it);
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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