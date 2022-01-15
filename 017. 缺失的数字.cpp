// 缺失的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int MissingNumber(vector<int>& nums) 
    {
        if (0 == nums.size()) return 1;

        int i = 0;
        std::sort(nums.begin(), nums.end());
        for (; i < nums.size(); ++i)
        {
            if (i != nums[i])
            {
                return i;
            }
        }

        return nums[i - 1] + 1;
    }
};

int main()
{
    Solution ss;
    std::vector<int> vec = { 0 };
    std::cout << ss.MissingNumber(vec) << std::endl;
}
