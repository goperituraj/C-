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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    map<ll, ll> mp;

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }

    ll cnt = 0;
    ll cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        ll complement = k - v[i];
        if (mp[v[i]] > 0 && mp[complement] > 0)
        {
            if (v[i] == complement)
            {
                if (mp[v[i]] >= 2)
                {
                    cnt++;
                    mp[v[i]] -= 2;
                }
            }
            else
            {

                cnt++;
                mp[v[i]]--;
                mp[complement]--;
            }
        }
        else if (mp[v[i]] > 0 && mp.find(complement) == mp.end())
            cnt2++;
    }

    if (cnt2 % 2 != 0)
    {
        cnt--;
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
