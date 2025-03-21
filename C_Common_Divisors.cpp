#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll findGCD(vector<ll> &nums)
{
    if (nums.empty())
        return 0;
    ll result = nums[0];
    for (ll num : nums)
    {
        result = __gcd(result, num);
        if (result == 1)
            break;
    }
    return result;
}

ll nfactors(ll num)
{
    ll count = 0;
    for (ll i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
            if (i != num / i)
                count++;
        }
    }
    return count;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll result = findGCD(v);
    result = nfactors(result);
    cout << result << endl;
}

int main()
{
    fastio();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
