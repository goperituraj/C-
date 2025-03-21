#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

vector<ll> getPrimeFactors(ll n)
{
    n = abs(n);
    vector<ll> factors;
    for (ll i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }
    return factors;
}

void removeCommonFactors(vector<ll> &factorsA, vector<ll> &factorsB)
{
    vector<ll> resultA, resultB;
    sort(factorsA.begin(), factorsA.end());
    sort(factorsB.begin(), factorsB.end());

    auto itA = factorsA.begin();
    auto itB = factorsB.begin();

    while (itA != factorsA.end() && itB != factorsB.end())
    {
        if (*itA == *itB)
        {
            ++itA;
            ++itB;
        }
        else if (*itA < *itB)
        {
            resultA.push_back(*itA++);
        }
        else
        {
            resultB.push_back(*itB++);
        }
    }

    while (itA != factorsA.end())
    {
        resultA.push_back(*itA++);
    }
    while (itB != factorsB.end())
    {
        resultB.push_back(*itB++);
    }

    factorsA = resultA;
    factorsB = resultB;
}
bool allZero(const vector<ll> &v)
{
    for (ll x : v)
    {
        if (x != 0)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    map<pair<ll, ll>, ll> factorMap;
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 0)
            continue;
        vector<ll> factorsA = getPrimeFactors(a[i]);
        vector<ll> factorsB = getPrimeFactors(b[i]);
        if (a[i] == 0 && b[i] == 0)
            cnt++;
        removeCommonFactors(factorsA, factorsB);

        ll finalA = 1, finalB = 1;
        for (ll factor : factorsA)
        {
            finalA *= factor;
        }
        for (ll factor : factorsB)
        {
            finalB *= factor;
        }
        if (a[i] < 0 && b[i] < 0 || a[i] > 0 && b[i] > 0)
            factorMap[{-finalA, -finalB}]++;
        else
        {
            factorMap[{finalA, finalB}]++;
        }
    }
    ll maxValue = 0;
    pair<ll, ll> maxPair;
    for (const auto &entry : factorMap)
    {
        if (entry.second > maxValue)
        {
            maxValue = entry.second;
            maxPair = entry.first;
        }
    }
    bool f1 = allZero(a);
    bool f2 = allZero(b);
    if (f1 && f2)
    {
        cout << n << endl;
        return;
    }
    if (f1)
    {
        cout << 0 << endl;
        return;
    }
    if (f2)
    {
        cout << n << endl;
        return;
    }
    cout << maxValue + cnt << endl;
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
