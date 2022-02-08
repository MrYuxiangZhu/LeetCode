// 删除有序数组中的重复项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        if (nums.size() <= 1) return nums.size();

        int slow = 0;
        int fast = 1;

        while (fast < nums.size())
        {
            if (nums[slow] != nums[fast])
            {
                nums[++slow] = nums[fast];
            }

            fast++;
        }

        return slow + 1;
    }
};

int main()
{
    Solution ss;
    std::vector<int> vec = { 1, 1, 2 };
    std::cout << ss.removeDuplicates(vec) << std::endl;
    return 0;
}