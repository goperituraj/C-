#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    string s;
    cin >> s;
    string target = "atcoder";
    ll swaps = 0;

    for (int i = 0; i < target.length(); i++)
    {
        int idx = s.find(target[i]);
        while (idx > i)
        {
            swap(s[idx], s[idx - 1]);
            idx--;
            swaps++;
        }
    }

    cout << swaps << endl;
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
