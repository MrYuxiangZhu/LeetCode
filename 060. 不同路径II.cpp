// 060. 不同路径II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if (obstacleGrid.size() == 0)
        {
            return 0;
        }

        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i)
        {
            if (i > 0)
            {
                dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
            }
            else
            {
                dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : 1;
            }
        }

        for (int j = 0; j < cols; ++j)
        {
            if (j > 0)
            {
                dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j - 1];
            }
            else
            {
                dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : 1;
            }
        }

        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

class Solution1
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>&obstacleGrid) 
    {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                if (obstacleGrid[i][j] == 1) 
                {
                    f[j] = 0;
                    continue;
                }

                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) 
                {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};

int main()
{
    Solution1 ss;
    vector<vector<int>> roads = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
    cout << ss.uniquePathsWithObstacles(roads) << endl;
    return 0;
}
