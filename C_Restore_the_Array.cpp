#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

bool isValid(vector<ll> &ans, vector<ll> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (max(ans[i], ans[i + 1]) != v[i])
            return false;
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n - 1);
    vector<ll> ans;
    if (n == 1)
        cout << 2 << endl;
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }

    ll idx = -1;
    for (int i = 0; i < n - 2; i++)
    {
        if (v[i] > v[i + 1])
        {
            idx = i;
            }
    }
    vector<ll> temp;
    if (idx == -1)
    {
        ans.push_back(0);
        for (int i = 0; i < n - 1; i++)
        {
            ans.push_back(v[i]);
        }
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    else
    {
        ans.push_back(0);
        for (int i = 0; i <= idx; i++)
        {
            ans.push_back(v[i]);
        }
        ans.push_back(0);
        for (int i = idx + 1; i < n - 1; i++)
        {
            ans.push_back(v[i]);
        }
        temp = ans;
        temp.erase(temp.begin());
        if (!isValid(temp, v))
        {
            temp = ans;
            temp.erase(temp.begin() + idx);
            if (!isValid(temp, v))
            {
                temp = ans;
                temp.erase(temp.begin() + idx + 1);
                if (!isValid(temp, v))
                {
                    // temp = ans;
                    cout << -1 << endl;
                    return;
                }
            }
        }
        for (auto it : temp)
        {
            cout << it << " ";
        }
        cout << endl;
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
