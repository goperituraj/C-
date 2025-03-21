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

        vector<int> s(n), t(n);
        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;
            s[i] = (ch == '0') ? -1 : 1;
        }
        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;
            t[i] = (ch == '0') ? -1 : 1;
        }

        vector<int> p(n);
        p[0] = s[0];
        for (int i = 1; i < n; i++)
        {
            p[i] = p[i - 1] + s[i];
        }

        int cnt = 0;
        bool f = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != t[i] && p[i] != 0 && cnt % 2 == 0)
            {
                f = false;
            }
            else if (s[i] == t[i] && cnt % 2 != 0 && p[i] != 0)
            {
                f = false;
            }
            else if (s[i] != t[i] && p[i] == 0 && (cnt == 0 || cnt % 2 == 0))
            {
                cnt++;
            }
            else if (s[i] == t[i] && p[i] == 0 && cnt % 2 != 0)
            {
                cnt++;
            }
        }
        if (f)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}