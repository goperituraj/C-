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
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    set<ll> st;
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i] < v[i + 1] && v[i] > v[i - 1])
        {
            st.insert(v[i]);
        }
        else if (v[i] < v[i - 1] && v[i] > v[i + 1])
        {
            st.insert(v[i]);
        }
    }
    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        if (st.find(v[i]) == st.end())
        {
            ans.push_back(v[i]);
        }
    }
    cout << ans.size() << endl;
    ll k = ans.size();
    for (int i = 0; i < k; i++)
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