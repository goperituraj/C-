#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    set<ll> st1, st2, st3, st4, st0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            st1.insert(i + 1);
        if (a[i] == -1)
            st3.insert(i + 1);
        else
            st0.insert(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] == 1)
            st2.insert(i + 1);
        if (b[i] == -1)
            st4.insert(i + 1);
        else
            st0.insert(i + 1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (st1.find(i) != st1.end() && st2.find(i) != st2.end())
        {
            if (st1.size() >= st2.size())
                st1.erase(i);
            else
                st2.erase(i);
        }
    }

    for (auto it = st3.begin(); it != st3.end();)
    {
        if (st2.find(*it) != st2.end() || st0.find(*it) != st0.end())
            it = st3.erase(it);
        else
            ++it;
    }

    for (auto it = st4.begin(); it != st4.end();)
    {
        if (st1.find(*it) != st1.end() || st0.find(*it) != st0.end())
            it = st4.erase(it);
        else
            ++it;
    }

    set<ll> st5(st3.begin(), st3.end());
    st5.insert(st4.begin(), st4.end());

    int s1 = st1.size(), s2 = st2.size(), s3 = st5.size();
    while (s3 > 0)
    {
        if (s1 >= s2)
            s1--;
        else
            s2--;
        s3--;
    }

    cout << min(s1, s2) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
