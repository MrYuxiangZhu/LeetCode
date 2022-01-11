// 三数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//示例 1：
//
//输入：nums = [-1, 0, 1, 2, -1, -4]
//输出： [[-1, -1, 2], [-1, 0, 1]]
//示例 2：
//
//输入：nums = []
//输出：[]
//示例 3：
//
//输入：nums = [0]
//输出：[]


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static std::vector<std::vector<int>> ThreeSum(std::vector<int>& nums)
    {
        int len = nums.size();
        std::vector<std::vector<int>> ans(0, std::vector<int>(0, 0));
        if (len == 0) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int k = len - 1;
            for (int j = i + 1; j < len; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                while (j < k && nums[i] + nums[j] + nums[k] > 0)
                {
                    --k;
                }

                if (j == k)
                {
                    break;
                }

                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    ans.emplace_back(std::vector<int>{nums[i], nums[j], nums[k]});
                }
            }
        }

        return ans;
    }
};

int main()
{
    std::vector<std::vector<int>> res;
    std::vector<int> vec = { -1, 0, 1, 2, -1, -4 };
    res = Solution::ThreeSum(vec);
    return 0;
}
