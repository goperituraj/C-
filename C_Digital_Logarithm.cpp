#include <bits/stdc++.h>
using namespace std;

// Function f(x): returns the number of digits in x (base‑10)
int countDigits(int x)
{
    if (x == 0)
        return 1;
    int cnt = 0;
    while (x)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

// Cancel common occurrences from two frequency maps.
// For every number present in both maps, remove min(freqA, freqB) from both.
void cancelCommon(map<int, int> &freqA, map<int, int> &freqB)
{
    // We iterate over a copy of freqA's keys (to avoid iterator invalidation).
    vector<int> keys;
    for (auto &p : freqA)
    {
        keys.push_back(p.first);
    }
    for (int key : keys)
    {
        if (freqB.count(key))
        {
            int common = min(freqA[key], freqB[key]);
            freqA[key] -= common;
            freqB[key] -= common;
            if (freqA[key] == 0)
            {
                freqA.erase(key);
            }
            if (freqB[key] == 0)
            {
                freqB.erase(key);
            }
        }
    }
}

// This function simulates the operations following your idea.
void solve()
{
    int n;
    cin >> n;
    vector<int> arrA(n), arrB(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arrA[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arrB[i];
    }

    // Build frequency maps for the two arrays.
    map<int, int> freqA, freqB;
    for (int x : arrA)
        freqA[x]++;
    for (int x : arrB)
        freqB[x]++;

    long long operations = 0;

    // Cancel out common occurrences initially.
    cancelCommon(freqA, freqB);

    // We'll simulate operations until the extra (unmatched) frequencies vanish.
    while (!freqA.empty() || !freqB.empty())
    {
        bool transformed = false;

        // --- Process freqA: Look for any extra number > 9.
        for (auto it = freqA.begin(); it != freqA.end();)
        {
            if (it->first > 9)
            {
                // Transform one occurrence of this number.
                int key = it->first;
                operations++;
                // Decrease its frequency by one.
                it->second--;
                int newVal = countDigits(key);
                freqA[newVal]++; // insert the transformed value
                // Erase the key if its count becomes 0.
                if (it->second == 0)
                {
                    // Note: since we break right after transformation, safe to erase.
                    freqA.erase(it++);
                }
                else
                {
                    ++it;
                }
                transformed = true;
                break; // perform one operation at a time, then cancel common.
            }
            else
            {
                ++it;
            }
        }
        if (transformed)
        {
            cancelCommon(freqA, freqB);
            continue;
        }

        // --- Process freqB: Look for any extra number > 9.
        for (auto it = freqB.begin(); it != freqB.end();)
        {
            if (it->first > 9)
            {
                int key = it->first;
                operations++;
                it->second--;
                int newVal = countDigits(key);
                freqB[newVal]++;
                if (it->second == 0)
                {
                    freqB.erase(it++);
                }
                else
                {
                    ++it;
                }
                transformed = true;
                break;
            }
            else
            {
                ++it;
            }
        }
        if (transformed)
        {
            cancelCommon(freqA, freqB);
            continue;
        }

        // --- Now, look for one-digit numbers (from 2 to 9) in freqA.
        for (auto it = freqA.begin(); it != freqA.end();)
        {
            if (it->first >= 2 && it->first <= 9)
            {
                int key = it->first;
                operations++;
                it->second--;
                // f(x) for any one-digit number (except 1) is 1.
                freqA[1]++;
                if (it->second == 0)
                {
                    freqA.erase(it++);
                }
                else
                {
                    ++it;
                }
                transformed = true;
                break;
            }
            else
            {
                ++it;
            }
        }
        if (transformed)
        {
            cancelCommon(freqA, freqB);
            continue;
        }

        // --- Then, do the same for freqB (for numbers in [2,9]).
        for (auto it = freqB.begin(); it != freqB.end();)
        {
            if (it->first >= 2 && it->first <= 9)
            {
                int key = it->first;
                operations++;
                it->second--;
                freqB[1]++;
                if (it->second == 0)
                {
                    freqB.erase(it++);
                }
                else
                {
                    ++it;
                }
                transformed = true;
                break;
            }
            else
            {
                ++it;
            }
        }
        if (transformed)
        {
            cancelCommon(freqA, freqB);
            continue;
        }

        // If no transformation was possible but maps are not empty,
        // then (theoretically) the leftover numbers are 1's.
        // In that case, cancellation should have removed them if the arrays were similar.
        break;
    }

    cout << operations << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
