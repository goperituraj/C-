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
        set<ll> st;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            st.insert(x);
        }
        for (auto it : st)
        {
            v.push_back(it);
        }
        sort(v.begin(), v.end());
        ll mxp = n - 1;
        ll fans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            ll low = i;
            ll high = v.size() - 1;
            ll ans;
            while (low <= high)
            {

                ll mid = (low + high) / 2;
                if (v[mid] - v[i] <= mxp)
                {
                    low = mid + 1;
                    ans = mid;
                }
                else
                {
                    high = mid - 1;
                }
                        }
            fans = max(fans, ans - i + 1);
        }
        cout << fans << endl;
    }
}