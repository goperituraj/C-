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
    string s;
    cin >> s;
    s = '#' + s;
    vector<ll> one(n + 1);
    ll tone = 0;
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '*')
        {
            tone++;
            one[i] = tone;
            pref[i] = i;
        }
    }
    ll ans = INF;
    vector<ll> psum(n + 1);
    psum[1] = pref[1];
    for (int i = 2; i <= n; i++)
    {
        psum[i] += psum[i - 1] + pref[i];
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