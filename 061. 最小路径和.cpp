// 061. 最小路径和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        if (grid.size() == 0)
        {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i)
        {
            dp[i][0] = i == 0 ? grid[i][0] : grid[i][0] + dp[i - 1][0];
        }

        for (int j = 0; j < cols; ++j)
        {
            dp[0][j] = j == 0 ? grid[0][j] : grid[0][j] + dp[0][j - 1];
        }

        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

int main()
{
    Solution ss;
    vector<vector<int>> grid = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
    cout << ss.minPathSum(grid) << endl;
    return 0;
}
