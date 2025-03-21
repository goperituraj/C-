// Read the question correctly with proper dry run of given test cases
// Visulaize the problem
// then get the solution and then code
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// vector<ll> sa(vector<ll> v)
// {
//     vector<ll> arr;
// }
int main()
{
    int t = 1;
    // cin >> /t;
    while (t--)
    {
        ll n, h;
        cin >> n >> h;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll low = 0;
        ll high = n - 1;
        ll ans;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            vector<ll> temp = v;
            sort(temp.begin(), temp.begin() + mid + 1, greater<ll>());
            ll sum = 0;
            if (mid % 2 != 0)
            {
                for (int i = 0; i <= mid; i += 2)
                {
                    sum += max(temp[i], temp[i + 1]);
                }
            }
            else
            {
                for (int i = 0; i < mid; i += 2)
                {
                    sum += max(temp[i], temp[i + 1]);
                }
                sum += temp[mid];
            }
            if (sum <= h)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans + 1;
    }
}