#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll cnt = 0;
    ll left = 0, right = n - 1;

    while (right >= left)
    {
        ll sum = v[right];
        right--;
        while (left <= right && sum + v[left] <= w)
        {
            sum += v[left];
            left++;
        }

        cnt++;
    }

    cout << cnt << endl;
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
