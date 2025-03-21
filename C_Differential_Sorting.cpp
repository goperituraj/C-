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
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> dup(v.begin(), v.end());
        sort(dup.begin(), dup.end());
        if (dup == v)
        {
            cout << 0 << endl;
        }
        else if (v[n - 2] - v[n - 1] > v[n - 2])
            cout << -1 << endl;
        else if (v[n - 2] <= v[n - 1])
        {
            cout << n - 2 << endl;
            for (int i = 1; i <= n - 2; i++)
            {
                cout << i << " " << n - 1 << " " << n << endl;
            }
        }
        else
            cout << -1 << endl;
    }
}