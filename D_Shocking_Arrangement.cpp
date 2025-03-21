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
    vector<ll> vp, vn;
    bool allZero = true;

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] != 0)
            allZero = false;
        if (v[i] >= 0)
            vp.push_back(v[i]);
        else
            vn.push_back(v[i]);
    }

    if (allZero)
    {
        cout << "No" << endl;
        return;
    }

    sort(vp.begin(), vp.end());
    sort(vn.begin(), vn.end());

    vector<ll> ans;
    ll s = vp.back() - vn.front();
    ans.push_back(vp[0]);

    ll m = vp.size();
    ll j = 0;
    ll k = vn.size();
    vector<ll> ps(n, 0);
    ps[0] = vp[0];

    for (int i = 1; i < m; i++)
    {
        if (ps[i - 1] + vp[i] > (s))
        {
            if (j < k)
            {
                ans.push_back(vn[j]);
                ans.push_back(vp[i]);
            }
            else
            {
                cout << "Nos" << endl;
                return;
            }
            j++;
        }
        else
        {
            ans.push_back(vp[i]);
        }
        ps[i] = ps[i - 1] + ans.back();
    }

    for (int l = j; l < k; l++)
    {
        ans.push_back(vn[l]);
    }

    cout << "Yes" << endl;
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
