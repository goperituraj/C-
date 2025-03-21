#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> freq;

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
    }

    vector<ll> pairs, singles;
    for (auto &entry : freq)
    {
        if (entry.second >= 4)
        {
            cout << entry.first << " " << entry.first << " " << entry.first << " " << entry.first << "\n";
            return;
        }
        else if (entry.second >= 2)
        {
            pairs.push_back(entry.first);
            if (entry.second > 2)
            {
                singles.push_back(entry.first);
            }
        }
        else
        {
            singles.push_back(entry.first);
        }
    }
    if (pairs.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    if (pairs.size() == 1)
    {
        sort(singles.begin(), singles.end());
        for (int i = 0; i < singles.size() - 1; i++)
        {
            ll diff = singles[i + 1] - singles[i];
            if (diff < 2 * pairs[0])
            {
                cout << pairs[0] << " " << pairs[0] << " " << singles[i] << " " << singles[i + 1] << "\n";
                return;
            }
        }
    }
    if (pairs.size() >= 2)
    {
        sort(pairs.rbegin(), pairs.rend());
        cout << pairs[0] << " " << pairs[0] << " " << pairs[1] << " " << pairs[1] << "\n";
        return;
    }
    cout << -1 << endl;
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
