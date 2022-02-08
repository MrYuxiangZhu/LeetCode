// 跳跃游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool canJump(vector<int>& nums) 
	{
		int max_far = 0;
		int end = 0;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			max_far = std::max(max_far, i + nums[i]);
			if (i == end)
			{
				end = max_far;
			}
		}

		return end >= nums.size() - 1;
	}
};

int main()
{
	Solution ss;
	std::vector<int> nums = { 0, 2, 3 };
	std::cout << ss.canJump(nums) << std::endl;
	return 0;
}
