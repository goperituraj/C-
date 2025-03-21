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
    string s, t;
    cin >> s >> t;

    map<char, ll> mp, mp2;

    for (int i = 1; i < s.length(); i++)
    {
        if (mp.find(s[i]) == mp.end())
        {
            mp[s[i]] = i + 1;
        }
    }

    for (int i = 0; i < t.length() - 1; i++)
    {
        mp2[t[i]] = t.length() - i;
    }

    ll mn = INF;
    char ch = '\0';
    ll idx1 = -1, idx2 = -1;

    for (auto &entry : mp)
    {
        char c = entry.first;
        if (mp2.find(c) != mp2.end())
        {
            ll sum = mp[c] + mp2[c];
            if (sum < mn)
            {
                ch = c;
                idx1 = mp[c];
                idx2 = mp2[c];
                mn = sum;
            }
        }
    }

    if (mn == INF)
    {
        cout << -1 << endl;
        return;
    }

    string k = "";
    k += s.substr(0, idx1 - 1);
    k += t.substr(t.length() - idx2);
    cout << k << endl;
}

int main()
{
    fastio();

    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
