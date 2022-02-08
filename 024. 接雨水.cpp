// 接雨水.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int ans = 0;
        int size = height.size();

        for (int i = 1; i < size - 1; ++i)
        {
            int max_left = 0, max_right = 0;
            for (int j = i; j > 0; --j)
            {
                max_left = std::max(max_left, height[j]);
            }

            for (int j = i; j < size; ++j)
            {
                max_right = std::max(max_right, height[j]);
            }

            ans += std::min(max_left, max_right) - height[i];
        }

        return ans;
    }
};

int main()
{
    return 0;
}
