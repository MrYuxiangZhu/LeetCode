// 字母异位词分组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		vector<vector<string>> ans;
		unordered_map<string, vector<string>> mpstr;

		for (string& str : strs)
		{
			string key = str;
			std::sort(key.begin(), key.end());
			mpstr[key].emplace_back(str);
		}

		for (auto iter = mpstr.begin(); iter != mpstr.end(); ++iter)
		{
			ans.emplace_back(iter->second);
		}

		return ans;
	}
};

int main()
{
	Solution ss;
	vector<string> vec = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> ans = ss.groupAnagrams(vec);
	return 0;
}
