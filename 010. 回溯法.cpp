#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BackTrack
{
public:
	vector<vector<int>> Permute(vector<int>& src);
private:
	void Backtrack(int index, vector<int>&nums, vector<int>& per, vector<vector<int>>& res);
private:
	vector<int> visited;
};

void BackTrack::Backtrack(int index, vector<int>& nums, vector<int>& per, vector<vector<int>>& res)
{
	if (index == nums.size())
	{
		res.emplace_back(per);
		return;
	}
	else
	{
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
			{
				continue;
			}

			visited[i] = 1;
			per.emplace_back(nums[i]);
			Backtrack(index + 1, nums, per, res);
			visited[i] = 0;
			per.pop_back();
		}
	}
}

vector<vector<int>> BackTrack::Permute(vector<int>& src)
{
	vector<vector<int>> result;
	vector<int> per;
	sort(src.begin(), src.end());
	visited.resize(src.size());
	Backtrack(0, src, per, result);

	return result;
}

int main()
{
	BackTrack bt;
	vector<int> vec = { 1, 2, 2, 3 };
	vector<vector<int>> result;
	result = bt.Permute(vec);
	for (auto it : result)
	{
		for (auto iter : it)
		{
			cout << iter << " ";
		}
		cout << endl;
	}
	return 0;
}