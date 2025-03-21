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
    if (n % 2 == 0)
    {
        map<char, ll> mp1;
        for (int i = 0; i < n; i += 2)
        {
            mp1[s[i]]++;
        }
        map<char, ll> mp2;
        for (int i = 1; i < n; i += 2)
        {
            mp2[s[i]]++;
        }
    }
    else
    {
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