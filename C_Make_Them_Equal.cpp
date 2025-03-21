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
        char ch;
        cin >> ch;
        string s;
        cin >> s;
        bool f = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ch)
                f = false;
        }

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ch)
            {
                if ((i + 1) % 2 == 0)
                {
                    flag = false;
                }
            }
        }

        if (f)
        {
            cout << 0 << endl;
        }
        else if (flag)
        {
            cout << 1 << endl;
            cout << 2 << endl;
        }
        else if (s[n - 1] == ch)
        {
            cout << 1 << endl;
            cout << n << endl;
        }
        else
        {
            ll idx = -1;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == ch)
                {
                    if (n % (i + 1) != 0)
                    {
                        idx = i;
                        break;
                    }
                }
            }
            if (idx != -1)
            {
                cout << 1 << endl;
                cout << idx + 1 << endl;
            }
            else
            {
                cout << 2 << endl;
                cout << n << " " << n - 1 << endl;
            }
        }
    }
}