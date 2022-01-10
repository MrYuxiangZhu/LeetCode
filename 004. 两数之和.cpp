// 两数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    static vector<int> TwoSum(vector<int>& nums, int target) 
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    return { i, j };
                }
            }
        }

        return { };
    }
};

int main()
{
    std::vector<int> vec = { 2,7,11,15 };
    std::vector<int> res = Solution::TwoSum(vec, 13);
    return 0;
}
