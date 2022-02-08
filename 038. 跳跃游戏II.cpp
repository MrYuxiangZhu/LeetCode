// 跳跃游戏II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int jump(vector<int>& nums) 
	{
		int max_far = 0;
		int end = 0;
		int step = 0;

		for (int i = 0; i < nums.size() - 1; ++i)
		{
			max_far = std::max(max_far, i + nums[i]);
			if (i == end)
			{
				end = max_far;
				step++;
			}
		}

		return step;
	}
};
int main()
{
	Solution ss;
	std::vector<int> vec = { 2, 3, 1 };
	std::cout << ss.jump(vec) << std::endl;
	return 0;
}
