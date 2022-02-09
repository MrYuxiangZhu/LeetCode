// 合并区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
		if (intervals.size() == 0)
		{
			return { };
		}
		std::sort(intervals.begin(), intervals.end());
		vector<vector<int>> ranges;
		for (auto iter : intervals)
		{
			int L = iter[0], R = iter[1];
			if (!ranges.size() || ranges.back()[1] < L)
			{
				ranges.push_back({ L, R });
			}
			else
			{
				ranges.back()[1] = std::max(ranges.back()[1], R);
			}
		}

		return ranges;
	}
};

int main()
{
	Solution ss;
	vector<vector<int>> range = { { 1, 9 }, { 2, 5 }, { 19, 20 }, { 10, 11 }, { 12, 20 }, { 0, 3 }, { 0, 1 }, { 0, 2 } };
	range = ss.merge(range);
	return 0;
}
