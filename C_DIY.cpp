#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> freq;

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
    }

    vector<ll> c;
    for (auto it : freq)
    {
        ll x = it.second;
        while (x >= 2)
        {
            c.push_back(it.first);
            x = x - 2;
        }
    }
    sort(c.begin(), c.end());

    if (c.size() >= 4)
    {
        ll A = c[0], B = c[1], C = c[c.size() - 2], D = c[c.size() - 1];
        ll area1 = (D - A) * (C - B);
        ll area2 = (C - A) * (D - B);
        cout << "Yes" << "\n";
        if (area1 >= area2)
        {
            cout << A << " " << B << " " << D << " " << B << " "
                 << A << " " << C << " " << D << " " << C << "\n";
        }
        else
        {
            cout << A << " " << B << " " << C << " " << B << " "
                 << A << " " << D << " " << C << " " << D << "\n";
        }
    }
    else
    {
        cout << "no" << endl;
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
