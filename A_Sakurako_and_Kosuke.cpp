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
        vector<ll> v;
        for (int i = 1; i <= 1000000; i++)
        {
            if (i % 2 != 0)
                v.push_back(-(2 * i - 1));
            else
                v.push_back((2 * i - 1));
        }
        ll sum = 0;
        ll i = 0;
        ll idx = -1;
        while (sum <= n || sum >= -n)
        {

            sum += v[i];
            // cout << sum << endl;
            i++;
            if (sum > n || sum < -n)
            {
                idx = i;
                break;
            }
        }
        if (idx % 2 != 0)
        {
            cout << "Sakurako" << endl;
        }
        else
        {
            cout << "Kosuke" << endl;
        }
    }
}