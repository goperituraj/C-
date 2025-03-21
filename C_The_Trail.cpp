#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solveTestCase(int n, int m, const string &path, vector<vector<long long>> &grid)
{
    // Calculate the initial row and column sums excluding the path cells
    vector<long long> rowSum(n, 0), colSum(m, 0);

    // Iterate through the grid to compute the row and column sums, ignoring path cells
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0) // We don't consider the path cells (those are 0)
            {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }
    }

    // Process the path and assign values to the cells in the path
    int x = 0, y = 0; // Starting position for path (top-left corner)
    for (char step : path)
    {
        // The value to assign to this path cell such that rowSum[x] + colSum[y] = 0
        long long value = -(rowSum[x]);

        // Assign the calculated value to the grid cell
        grid[x][y] = value;

        // // Update row and column sums after assignment
        // rowSum[x] += value;
        // colSum[y] += value;

        // Move to the next cell in the path
        if (step == 'D')
            x++;
        else if (step == 'R')
            y++;
    }

    // Output the restored grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n, m;
        string path;
        cin >> n >> m >> path;

        // Read the grid
        vector<vector<long long>> grid(n, vector<long long>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        // Solve the test case
        solveTestCase(n, m, path, grid);
    }

    return 0;
}
