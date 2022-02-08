// 组合总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> combine;
        if (candidates.size() == 0) return result;
        backtrack(candidates, target, combine, result, 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<int>& combine, vector<vector<int>>& result, int index)
    {
        if (index == candidates.size())
        {
            return;
        }

        if (target == 0)
        {
            result.emplace_back(combine);
            return;
        }

        if (target - candidates[index] >= 0)
        {
            combine.emplace_back(candidates[index]);
            backtrack(candidates, target - candidates[index], combine, result, index);
            combine.pop_back();
        }

        backtrack(candidates, target, combine, result, index + 1);
    }
};

class Solution1
{
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int index)
    {
        if (index == candidates.size())
        {
            return;
        }

        if (target == 0)
        {
            ans.emplace_back(combine);
            return;
        }

        if (target - candidates[index] >= 0)
        {
            combine.emplace_back(candidates[index]);
            backtrack(candidates, target - candidates[index], ans, combine, index);
            combine.pop_back();
        }

        backtrack(candidates, target, ans, combine, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combine;
        if (candidates.size() == 0) return result;
        backtrack(candidates, target, result, combine, 0);
        return result;
    }
};

int main()
{
    Solution ss;
    std::vector<std::vector<int>> ans;
    std::vector<int> vec = { 2, 3, 6, 7 };
    ans = ss.combinationSum(vec, 7);
    return 0;
}
