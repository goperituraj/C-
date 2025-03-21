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
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ll sum = 0;
    for (auto i : arr)
        sum += i;
    ll ans = 0;
    ans += ((sum + 1) / 2);
    sum /= 2;
    ll j = n - 1;
    while (sum > 0)
    {
        sum -= arr[j];
        ans++;
        j--;
    }

    cout << ans << '\n';
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