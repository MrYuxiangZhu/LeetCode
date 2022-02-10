// 059. 不同路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution ss;
    std::cout << ss.uniquePaths(3, 2) << std::endl;
    return 0;
}
