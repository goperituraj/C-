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
        ll n;
        cin >> n;
        vector<vector<ll>> v(n, vector<ll>(2));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> v[i][j];
            }
        }
        ll low = v[0][0];
        ll high = v[0][1];
        // int i=1;
        ll ans = 0;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            for (int i = 1; i < n; i++)
            {
                if (mid - v[i][0] >= 0 && v[i][1] - mid >= 0)
                {
                    low = mid - 1;
                    ans = mid;
                }
                else
                    high = mid + 1;
            }
        }
    }
}