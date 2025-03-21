#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll> temp;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            temp.push_back(i);
        }
    }

    if (temp.empty())
    {
        // If no 'W' exists, place `k` consecutive 'W' at the start
        cout << max(0LL, 2 * min(n, k) - 1) << endl;
        return;
    }

    // Store all gaps between existing 'W'
    vector<pair<ll, pair<ll, ll>>> d;
    for (int i = 0; i < (int)temp.size() - 1; i++)
    {
        d.push_back({temp[i + 1] - temp[i] - 1, {temp[i], temp[i + 1]}});
    }

    sort(d.begin(), d.end()); // Fill smallest gaps first

    for (auto &gap : d)
    {
        if (gap.first <= k)
        {
            ll st = gap.second.first;
            ll end = gap.second.second;
            for (int j = st + 1; j <= end - 1; j++)
            {
                s[j] = 'W';
                k--;
                if (k == 0)
                    break;
            }
        }
    }

    // Choose a middle `W` as the starting point
    int midIndex = temp.size() / 2;
    ll start_pos = temp[0];

    // Expand right first
    for (int i = start_pos + 1; i < n && k > 0; i++)
    {
        if (s[i] == 'L')
        {
            s[i] = 'W';
            k--;
        }
    }

    // Expand left after right
    for (int i = start_pos - 1; i >= 0 && k > 0; i--)
    {
        if (s[i] == 'L')
        {
            s[i] = 'W';
            k--;
        }
    }

    // Compute the final score
    ll ans = (s[0] == 'W') ? 1 : 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'W')
        {
            ans += (s[i - 1] == 'W') ? 2 : 1;
        }
    }

    cout << ans << endl;
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
