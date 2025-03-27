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

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string o = s;
    reverse(s.begin(), s.end());
    string d = s;
    for (int i = 0; i < n; i++)
    {
        if (o[i] < d[i])
        {
            cout << "yes" << endl;
            return;
        }
        else if (o[i] == d[i])
        {
            continue;
        }
        else
        {
            if (k >= 1)
            {
                cout << "yes" << endl;
                return;
            }
            else
            {
                cout << "no" << endl;
                return;
            }
        }
    }
    cout << "no" << endl;
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