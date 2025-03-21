#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;
        ll n = s.length();
        ll idx = -1;

        // Find the first adjacent matching pair
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                idx = i;
                break;
            }
        }

        if (idx != -1)
        {
            cout << s[idx] << s[idx + 1] << endl;
        }
        else if (n >= 4)
        {
            cout << s[0] << s[1] << s[2] << s[3] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
