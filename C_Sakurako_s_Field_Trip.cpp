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
        ll cnt = 0;
        // for (int i = 0; i < n - 1; i++)
        // {
        //     if (v[i] == v[i + 1])
        //         cnt++;
        // }
        ll i = 1;
        ll j = n - 2;
        while (i < j)
        {
            if ((v[i] == v[i - 1] || v[j] == v[j + 1]) && (v[i] != v[j + 1] && v[j] != v[i - 1]))
            {
                swap(v[i], v[j]);
            }
            i++;
            j--;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] == v[i + 1])
                cnt++;
        }
        cout << cnt << endl;
    }
}