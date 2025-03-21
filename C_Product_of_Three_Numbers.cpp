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

vector<ll> primeFactors(int n)
{
    vector<ll> factors;
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
    {
        factors.push_back(n);
    }
    return factors;
}

void solve()
{

    ll n;
    cin >> n;
    vector<ll> factors = primeFactors(n);
    ll a = factors[0];
    ll s = factors.size();
    ll b = factors[1];
    int i = 2;
    while (b == a)
    {
        b *= factors[i];
        i++;
    }
    int j = i;
    ll c = 1;
    while (j < s)
    {
        c *= factors[j];
        j++;
    }
    if (b == 1 || c == 1 || a == b || a == c || b == c)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
        cout << a << " " << b << " " << c << endl;
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