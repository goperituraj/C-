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
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll requiredZero = 3, requiredOne = 1, requiredFive = 1, requiredThree = 1, requiredTwo = 2;
    ll countZero = 0, countOne = 0, countTwo = 0, countFive = 0, countThree = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 2)
            countTwo++;
        else if (v[i] == 0)
            countZero++;
        else if (v[i] == 5)
            countFive++;
        else if (v[i] == 3)
            countThree++;
        else if (v[i] == 1)
            countOne++;

        if (countTwo >= requiredTwo && countOne >= requiredOne &&
            countFive >= requiredFive && countThree >= requiredThree &&
            countZero >= requiredZero)
        {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << 0 << endl;
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
