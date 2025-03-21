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
vector<ll> ans;
void solve()
{
    ll l, r;
    cin >> l >> r;
    while (true)
    {
        ll p = 1;
        while (p * 2 <= r)
        {
            p *= 2;
        }

        if (p > l && p <= r)
        {
            ll k;
            for (int i = l; i <= r; i++)
            {
                if (i != p && i != p - 1)
                {
                    k = i;
                    break;
                }
            }
            ll sum = 0;
            for (int i = 0; i < ans.size(); i++)
            {
                sum += ans[i];
            }

            cout << p + sum << " " << p - 1 + sum << " " << k + sum << endl;
            return;
        }
        else
        {
            l -= p;
            r -= p;
            ans.push_back(p);
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
        ans.clear();
        solve();
    }

    return 0;
}