// 最大子数组和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	//int maxSubArray(vector<int>& nums)
	//{
	//	//类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
	//	int max = INT_MIN;
	//	int numsSize = int(nums.size());
	//	for (int i = 0; i < numsSize; i++)
	//	{
	//		int sum = 0;
	//		for (int j = i; j < numsSize; j++)
	//		{
	//			sum += nums[j];
	//			if (sum > max)
	//			{
	//				max = sum;
	//			}
	//		}
	//	}

	//	return max;
	//}

	int maxSubArray(vector<int>& nums)
	{
		int maxsum = nums[0];
		int dp = 0;

		for (auto& it : nums)
		{
			dp = std::max(dp + it, it);
			maxsum = std::max(maxsum, dp);
		}

		return maxsum;
	}
};

int main()
{
	Solution ss;
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	std::cout << ss.maxSubArray(nums) << std::endl;
	return 0;
}
