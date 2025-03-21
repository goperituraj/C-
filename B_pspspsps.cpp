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

void solve()
{

    ll n;
    cin >> n;
    ll k = n;
    string s;
    cin >> s;
    int idx1 = -1, idx2 = n;
    int cnts = 0, cntp = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 's')
        {
            cnts++;
            idx1 = i;
        }
        else if (s[i] == 'p')
        {

            idx2 = min(i, idx2);
            cntp++;
        }
    }
    if (cnts == 0 || cntp == 0)
    {
        cout << "yes" << endl;
    }
    else if (idx1 > idx2)
    {
        cout << "no" << endl;
    }
    else if (cnts > 1 && cntp > 1)
    {
        cout << "no" << endl;
    }
    else
    {
        if ((s[0] == 's' && cnts == 1) || (s[n - 1] == 'p' && cntp == 1))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
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