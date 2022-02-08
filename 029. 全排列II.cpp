// 全排列II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> ans;
		vector<int> combine;
		vector<int> visit(nums.size(), 0);
		std::sort(nums.begin(), nums.end());
		backtrack(nums, visit, combine, ans, 0);
		return ans;
	}
private:
	void backtrack(vector<int>& nums, vector<int>& visit, vector<int>& combine, vector<vector<int>>& ans, int index)
	{
		if (index == nums.size())
		{
			ans.emplace_back(combine);
			return;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]))
			{
				continue;
			}

			visit[i] = 1;
			combine.emplace_back(nums[i]);
			backtrack(nums, visit, combine, ans, index + 1);
			combine.pop_back();
			visit[i] = 0;
		}
	}
};

int main()
{
	Solution ss;
	vector<vector<int>> ans;
	vector<int> vec = { 3, 3, 0, 3 };
	ans = ss.permuteUnique(vec);

	for (auto iter : ans)
	{
		for (auto it : iter)
		{
			std::cout << it << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
