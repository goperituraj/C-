#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;
vector<vector<long long>> memo;

// Recursive function to calculate counts
pair<long long, long long> countSubarrays(int i)
{
    if (i < 0)
        return {0, 0};
    if (memo[i][0] != -1)
        return {memo[i][0], memo[i][1]};

    auto it = countSubarrays(i - 1);
    long long prevNeg = it.first;
    long long prevPos = it.second;
    long long currNeg = 0, currPos = 0;
    if (a[i] > 0)
    {
        currPos = prevPos + 1;
        currNeg = prevNeg;
    }
    else
    {
        currPos = prevNeg;
        currNeg = prevPos + 1;
    }

    memo[i][0] = currNeg;
    memo[i][1] = currPos;

    return {currNeg, currPos};
}

int main()
{
    cin >> n;
    a.resize(n);
    memo.assign(n, vector<long long>(2, -1));

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    long long totalNeg = 0, totalPos = 0;
    for (int i = 0; i < n; ++i)
    {
        auto it = countSubarrays(i);
        long long currNeg = it.first;
        long long currPos = it.second;
        totalNeg += currNeg;
        totalPos += currPos;
    }

    cout << totalNeg << " " << totalPos << endl;
    return 0;
}
