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

    int n, a, b;
    cin >> n >> a >> b;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += 'R';
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = i; j < n; j += (i + 1))
        {
            cnt++;
        }
        if (cnt == b)
        {
            for (int j = i; j < n; j += (i + 1))
            {
                s[j] = 'B';
            }
            cout << s << endl;
            return;
        }
        else if (cnt < b)
        {
            // cnt--;
            int k = i - 1;
            for (int j = k; j < n && b; j += (k + 1))
            {
                s[j] = 'B';
                b--;
            }
            cout << s << endl;
            return;
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