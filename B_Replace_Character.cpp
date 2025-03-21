#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'a']++;
    }

    char maxChar = 'a';
    int maxFreq = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            maxChar = 'a' + i;
        }
    }

    char minChar = 'a';
    int minFreq = INT_MAX;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0 && freq[i] < minFreq && ('a' + i) != maxChar)
        {
            minFreq = freq[i];
            minChar = 'a' + i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == minChar)
        {
            s[i] = maxChar;
            break;
        }
    }

    cout << s << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
