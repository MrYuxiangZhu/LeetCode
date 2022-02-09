// 055. 插入区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        if (intervals.size() == 0)
        {
            return { newInterval };
        }

        intervals.emplace_back(newInterval);
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for (auto& iter : intervals)
        {
            int L = iter[0], R = iter[1];
            if (!merged.size() || merged.back()[1] < L)
            {
                merged.push_back({ L, R });
            }
            else
            {
                merged.back()[1] = std::max(merged.back()[1], R);
            }
        }

        return merged;
    }
};

int main()
{
    Solution ss;
    vector<vector<int>> intervals = { { 1, 3 }, { 6, 9 } };
    vector<int> range = { 2, 5 };
    intervals = ss.insert(intervals, range);
    return 0;
}
