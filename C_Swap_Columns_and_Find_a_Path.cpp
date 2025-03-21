#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> topRow(n), bottomRow(n);
    for (int i = 0; i < n; i++)
        cin >> topRow[i];
    for (int i = 0; i < n; i++)
        cin >> bottomRow[i];

    vector<pair<int, int>> columns(n);
    for (int i = 0; i < n; i++)
    {
        columns[i] = {topRow[i], bottomRow[i]};
    }

    sort(columns.begin(), columns.end());

    int maxColIdx = -1, maxColSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int colSum = columns[i].first + columns[i].second;
        if (colSum > maxColSum && columns[i].second >= 0)
        {
            maxColSum = colSum;
            maxColIdx = i;
        }
    }

    vector<pair<int, int>> leftPart, rightPart;
    for (int i = 0; i < n; i++)
    {
        if (i == maxColIdx)
            continue;
        if (columns[i].first < columns[i].second)
        {
            rightPart.push_back(columns[i]);
        }
        else
        {
            leftPart.push_back(columns[i]);
        }
    }

    vector<pair<int, int>> finalOrder = leftPart;
    finalOrder.push_back(columns[maxColIdx]);
    maxColSum = -1e9;
    finalOrder.insert(finalOrder.end(), rightPart.begin(), rightPart.end());

    for (int i = 0; i < n; i++)
    {
        int colSum = finalOrder[i].first + finalOrder[i].second;
        if (colSum > maxColSum)
        {
            maxColSum = colSum;
            maxColIdx = i;
        }
    }

    int topSum = 0, bottomSum = 0;
    for (int i = 0; i <= maxColIdx; i++)
    {
        topSum += finalOrder[i].first;
    }

    for (int i = maxColIdx; i < finalOrder.size(); i++)
    {
        bottomSum += finalOrder[i].second;
    }

    int maxPathSum = topSum + bottomSum;
    cout << maxPathSum << endl;
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
