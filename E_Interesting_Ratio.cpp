#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll N = 1e7 + 5;
vector<bool> is_prime(N, true);
vector<ll> primes;
vector<ll> fcnt(N, 0);

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll lo = 0, hi = primes.size() - 1, idx = -1;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (i * primes[mid] <= n)
            {
                idx = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (idx != -1)
            ans += idx + 1;
    }
    cout << ans << endl;
}

int main()
{
    fastio();
    sieve(); // Precompute primes

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
