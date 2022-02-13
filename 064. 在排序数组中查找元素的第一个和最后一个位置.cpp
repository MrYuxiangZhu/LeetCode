// 064. 在排序数组中查找元素的第一个和最后一个位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            if (nums[left] != target)
            {
                ++left;
            }

            if (nums[right] != target)
            {
                --right;
            }

            if (nums[left] == nums[right])
            {
                break;
            }
        }

        if (left <= right)
        {
            return { left, right };
        }

        return { -1, -1 };
    }
};

class Solution1
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left = binarySearch(nums, target);
        int right = binarySearch(nums, target + 1);
        if (left == nums.size() || nums[left] != target)
        {
            return { -1, -1 };
        }

        return { left, right - 1 };
    }
private:
    int binarySearch(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main()
{
    Solution1 ss;
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    nums = ss.searchRange(nums, 10);
    return 0;
}
