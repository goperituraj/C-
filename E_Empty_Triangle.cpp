#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void s()
{
    ll n;
    cin >> n;
    vector<ll> p;
    for (ll i = 1; i <= n; i++)
        p.push_back(i);

    ll a = p[0], b = p[1];
    ll c = p[2];

    for (ll i = 1; i <= 75; i++)
    {
        cout << "? " << a << " " << b << " " << c << endl;
        cout.flush();

        ll r;
        cin >> r;

        if (r == -1)
            exit(0);
        if (r == 0)
        {
            cout << "! " << a << " " << b << " " << c << endl;
            return;
        }
        c = r;
    }
}

int main()
{
    fastio();

    int t;
    cin >> t;
    while (t--)
    {
        s();
    }

    return 0;
}
