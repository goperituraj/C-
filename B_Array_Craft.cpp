// Read the question correctly with proper dry run of given test cases
// Visulaize the problem
// then get the solution and then code
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> ans(n + 5, 5);
        for (int i = x + 1; i <= n; i += 2)
        {
            ans[i] = -1;
            ans[i + 1] = 1;
        }

        for (int i = y - 1; i >= 1; i -= 2)
        {
            ans[i] = -1;
            ans[i - 1] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 5)
                ans[i] = 1;
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}