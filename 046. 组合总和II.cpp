// 组合总和II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> combine;
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, combine, result, 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<int>& combine, vector<vector<int>>& result, int index)
    {
        if (target == 0)
        {
            result.emplace_back(combine);
            return;
        }
        
        for (int i = index; i < candidates.size(); ++i)
        {
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            
            if (target - candidates[i] >= 0)
            {
                combine.emplace_back(candidates[i]);
                backtrack(candidates, target - candidates[i], combine, result, i + 1);
                combine.pop_back();
            }
        }
    }
};

int main()
{
    Solution ss;
    std::vector<int> vec = { 10, 1, 2, 7, 6, 1, 5 };
    std::vector<std::vector<int>> ans;
    ans = ss.combinationSum2(vec, 8);
    return 0;
}
