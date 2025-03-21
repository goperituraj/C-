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
    map<ll, bool> mp;
    for (int i = 1; i <= 2 * n; i++)
    {
        mp[i] = true;
    }
    set<pair<ll, ll>> st;
    ll i = 1, j = 2 * n;
    while (i < j)
    {
        st.insert({i, j});
        mp[i] = false;
        mp[j] = false;
        i++;
        j -= 2;
    }
    ll k = i - 1;
    j = 2 * n - (k - 1);
    while (i < j)
    {
        if (mp[i] && mp[j])
            st.insert({i, j});
        else
            break;
        mp[i] = false;
        mp[j] = false;
        i += 2;
        j--;
    }
    if (st.size() != n)
        cout << "no" << endl;
    else
    {
        cout << "yes" << endl;
        vector<pair<ll, ll>> m;
        for (auto it : st)
        {
            m.push_back({it.first, it.second});
        }

        sort(m.begin(), m.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return (a.first + a.second) < (b.first + b.second); });

        for (auto it : m)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
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