// 排列序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
	string getPermutation(int n, int k)
	{
		string strs;
		for (int i = 1; i <= n; ++i)
		{
			strs += to_string(i);
		}
		
		vector<string> ans;
		string combine;
		vector<int> visit(n, 0);
		int count = 0;
		backtrack(strs, k, combine, visit, ans, count, 0);
		return ans[k - 1];
	}
private:
	void backtrack(string& strs, int& k, string& combine, vector<int>& visit, vector<string>& ans, int& count, int index)
	{
		if (count == k)
		{
			return;
		}

		if (index == strs.size())
		{
			count++;
			ans.emplace_back(combine);
			return;
		}

		for (int i = 0; i < strs.size(); ++i)
		{
			if (visit[i] || (i > 0 && strs[i] == strs[i - 1] && !visit[i - 1]))
			{
				continue;
			}

			visit[i] = 1;
			combine.push_back(strs[i]);
			backtrack(strs, k, combine, visit, ans, count, index + 1);
			combine.pop_back();
			visit[i] = 0;
		}
	}
};

class Solution1
{
public:
	string getPermutation(int n, int k)
	{
		vector<vector<int>> ans;
		vector<int> combine;
		vector<int> visit(n, 0);
		int count = 0;
		backtrack(n, k, combine, visit, ans, count, 0);

		string str;
		for (int i = 0; i < n; ++i)
		{
			str += to_string(ans[k - 1][i]);
		}
		return str;
	}
private:
	void backtrack(int& nums, int& key, vector<int>& combine, vector<int>& visit, vector<vector<int>>& ans, int& count, int index)
	{
		if (count == key)
		{
			return;
		}

		if (index == nums)
		{
			count++;
			ans.emplace_back(combine);
			return;
		}

		for (int i = 1; i <= nums; ++i)
		{
			if (visit[i] || (i > 0 && !visit[i - 1]))
			{
				continue;
			}

			visit[i] = 1;
			combine.push_back(i);
			backtrack(nums, key, combine, visit, ans, count, index + 1);
			combine.pop_back();
			visit[i] = 0;
		}
	}
};

int main()
{
	Solution ss;
	std::cout << ss.getPermutation(3, 3) << std::endl;
	return 0;
}
