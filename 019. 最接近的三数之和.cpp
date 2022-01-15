// 最接近的三数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    static int ThreeSumClosest(vector<int>& nums, int target) 
    {
        std::sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); ++i)
        {
            int first = i + 1;
            int second = nums.size() - 1;
            while (first < second)
            {
                int sum = nums[i] + nums[first] + nums[second];
                if (abs(target - ans) > abs(target - sum))  /*新的三数之和更接近target*/
                {
                    ans = sum;
                }

                if (sum > target)   /*a, b 位置不变， c向左移动*/
                {
                    second--;
                }
                else if (sum < target) /*a, c 位置不变， b向右移动*/
                {
                    first++;
                }
                else
                {
                    return ans;
                }
            }
        }

        return ans;
    }
};

int main()
{
    std::vector<int> vec = { -1, 2, 1, -4 };
    std::cout << Solution::ThreeSumClosest(vec, 1) << std::endl;
}
