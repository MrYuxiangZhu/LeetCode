// 065. x 的平方根.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Solution 
{
public:
    int mySqrt(int x) 
    {
        if (x == 0)
        {
            return 0;
        }

        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};

class Solution1
{
public:
    int mySqrt(int x)
    {
        int left = 0;
        int right = x;
        int ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution1 ss;
    std::cout << ss.mySqrt(0) << std::endl;
    return 0;
}
