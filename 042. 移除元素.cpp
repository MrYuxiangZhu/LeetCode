// 移除元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int slow = 0;
        int fast = 0;

        while (fast < nums.size())
        {
            if (nums[fast] == val)
            {
                fast++;
            }
            else
            {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }

        return slow;
    }
};

int main()
{
    Solution ss;
    std::vector<int> vec = { 3, 2, 2, 3 };
    std::cout << ss.removeElement(vec, 3) << std::endl;

    return 0;
}