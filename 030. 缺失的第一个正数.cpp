// 缺失的第一个正数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution1 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_set<int> mset;
        for (int& num : nums)
        {
            mset.insert(num);
        }

        for (int i = 1; i <= nums.size(); ++i)
        {
            if (mset.find(i) == mset.end())
            {
                return i;
            }
        }

        return nums.size() + 1;
    }
};

class Solution2
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int size = nums.size();
        for (int& num : nums)
        {
            if (num <= 0)
            {
                num = size + 1;
            }
        }

        for (int i = 0; i < size; ++i)
        {
            int num = abs(nums[i]);
            if (num <= size)
            {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        for (int i = 0; i < size; ++i) 
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }

        return size + 1;
    }
};

int main()
{
    Solution2 ss;
    std::vector<int> vec = { 3, 4, -1, 1 };
    std::cout << ss.firstMissingPositive(vec) << std::endl;
    return 0;
}
