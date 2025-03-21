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

    ll nq;
    cin >> nq;
    string s;
    cin >> s;
    ll q;
    cin >> q;
    ll p = 0, n = 0;
    for (int i = 0; i < nq; i++)
    {
        if (s[i] == '+')
            p++;
        else
            n++;
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        if (a == b && p != n)
        {
            cout << "NO" << endl;
        }
        else if (p == n)
            cout << "YES" << endl;
        else if (p < n)
        {

            if (a % b != 0)
            {
                if (a * p == b * n)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
            {
                ll quo = a / b;
                if (n % p == 0 && n / p == quo)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    if (n % quo == p % quo)
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }
        }
        else
        {

            if (a % b != 0)
            {
                if (a * n == b * p)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
            {
                ll quo = a / b;
                if (p % n == 0 && p / n == quo)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    if (n % quo == p % quo)
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
            }
        }
    }
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