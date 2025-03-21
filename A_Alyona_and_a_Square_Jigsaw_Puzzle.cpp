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

        set<ll> st;
        ll layerSum = 1, increment = 8, totalPieces = 1;
        st.insert(totalPieces);
        while (totalPieces <= 1000000)
        {
            totalPieces += increment;
            increment += 8;
            st.insert(totalPieces);
        }

        ll cumulativeSum = 0, happyDays = 0;
        for (int i = 0; i < n; i++)
        {
            cumulativeSum += v[i];
            if (st.find(cumulativeSum) != st.end())
            {
                happyDays++;
            }
        }

        cout << happyDays << endl;
    }
    return 0;
}
