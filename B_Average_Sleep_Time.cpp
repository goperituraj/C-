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
    vector<double> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    double fsum = 0;
    double sum = 0;
    ll j = 0, i = 0;
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            fsum += v[i];
        }
        double ans = n - k + 1;
        fsum = (fsum) / ans;
        cout << fixed << setprecision(10) << fsum << endl;
        return;
    }
    while (j < n)
    {
        while (j - i + 1 <= k)
        {
            sum += v[j];
            j++;
        }
        fsum += sum;
        // cout << fsum << endl;
        sum -= v[i];
        i++;
        if (j >= n)
            break;
        // sum += v[i];
    }
    double ans = n - k + 1;
    fsum = (fsum) / ans;
    cout << fixed << setprecision(10) << fsum << endl;
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