// 四数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution 
{
public:
    static vector<vector<int>> fourSum1(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        if (0 == nums.size()) return res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                    {
                        continue;
                    }
                    for (int m = k + 1; m < nums.size(); ++m)
                    {
                        if (m > k + 1 && nums[m] == nums[m - 1])
                        {
                            continue;
                        }
                        int sum = nums[i] + nums[j] + nums[k] + nums[m];
                        if (sum == target)
                        {
                            res.emplace_back(std::vector<int>{ nums[i], nums[j], nums[k], nums[m] });
                        }
                    }
                }
            }
        }

        return res;
    }

    static vector<vector<int>> fourSum2(vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        if (0 == nums.size()) return res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                    {
                        continue;
                    }

                    int m = nums.size() - 1;
                    while (k < m && nums[i] + nums[j] + nums[k] + nums[m] > target)
                    {
                        m--;
                    }

                    if (k == m)
                    {
                        break;
                    }

                    if (nums[i] + nums[j] + nums[k] + nums[m] == target)
                    {
                        res.emplace_back(std::vector<int> { nums[i], nums[j], nums[k], nums[m] });
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    std::vector<int> nums = { 1000000000,1000000000,1000000000,1000000000};
    std::vector<std::vector<int>> res = Solution::fourSum2(nums, 0);

    for (auto iter : res)
    {
        for (auto it : iter)
        {
            std::cout << it << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
