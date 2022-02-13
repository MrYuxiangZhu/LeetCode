// 074. 交错字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n = s1.size();
        int m = s2.size();
        int t = s3.size();
        if (n + m != t) return false;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = true;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                int p = i + j - 1;
                if (i > 0)
                {
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
                }

                if (j > 0)
                {
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
