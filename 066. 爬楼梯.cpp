// 066. 爬楼梯.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int climbStairs(int n) 
    {
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                dp[i] = 1;
            }
            else if (i == 1)
            {
                dp[i] = 2;
            }
            else
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        
        return dp[n - 1];
    }
};

int main()
{
    Solution ss;
    std::cout << ss.climbStairs(6) << std::endl;
    return 0;
}
