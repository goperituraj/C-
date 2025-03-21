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
    ll n, x;
    cin >> n >> x;
    vector<ll> ans;
    set<ll> st;
    if (n == 1)
    {
        cout << x << endl;
        return;
    }
    ans.push_back(0);
    for (int j = 0; j < 30; j++)
    {
        if (x & 1 << j)
        {
            st.insert(j);
        }
    }
    for (int i = 1; i < n; i++)
    {
        ll x = i;
        bool f = true;
        for (int j = 0; j < 30; j++)
        {
            if ((x & 1 << j))
            {
                if (st.find(j) == st.end())
                {
                    f = false;
                    break;
                }
            }
        }
        if (!f)
            break;
        ans.push_back(x);
    }
    if (ans.size() < n)
    {
        while (ans.size() < n)
        {
            ans.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        ll m = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            m = m | ans[i];
        }
        if (m == x)
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
        }
        else
        {
            ans.pop_back();
            ans.push_back(x);
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
        }
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