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
    set<ll> st;
    ll cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        if ((u == 1 && st.count(v) > 0 || v == 1 && st.count(u) > 0) && st.count(1) == 0)
        {
            cnt++;
        }

        if (st.count(u) > 0 || st.count(v) > 0)
        {

            st.insert(u);
            st.insert(v);
        }
        else
        {

            cnt++;
            st.insert(u);
            st.insert(v);
        }
    }
    cout << cnt << endl;
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