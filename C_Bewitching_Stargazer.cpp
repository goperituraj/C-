#include <bits/stdc++.h>
using namespace std;
#define fast                              \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
    }
typedef long long ll;
ll k;

pair<ll, ll> call(ll n)
{
    if (n < k)
        return {0, 0};
    auto child = call(n / 2);
    ll child_sum = child.first;
    ll child_cnt = child.second;
    if (n & 1)
    {
        ll m = (n + 1) / 2;
        ll sum = m + child_sum * 2 + m * child_cnt;
        ll cnt = child_cnt * 2 + 1;
        return {sum, cnt};
    }
    ll m = n / 2;
    ll sum = child_sum * 2 + m * child_cnt;
    ll cnt = child_cnt * 2;
    return {sum, cnt};
}

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n >> k;
        cout << call(n).first << '\n';
    }
}
