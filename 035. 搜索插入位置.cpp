// 搜索插入位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) 
        {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) 
            {
                ans = mid;
                right = mid - 1;
            }
            else 
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution ss;
    std::vector<int> vec = { 1, 3, 5, 6 };
    std::cout << ss.searchInsert(vec, 7) << std::endl;
    return 0;
}
