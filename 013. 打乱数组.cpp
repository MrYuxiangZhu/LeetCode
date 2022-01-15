// 打乱数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
    Solution(vector<int>& nums) 
    {
        current = nums;
        original.resize(nums.size());
        copy(nums.begin(), nums.end(), original.begin());
    }

    vector<int> reset() 
    {
        return original;
    }

    vector<int> shuffle() 
    {
        for (int i = 0; i < current.size(); ++i)
        {
            int j = i + rand() % (current.size() - i);
            std::swap(current[i], current[j]);
        }

        return current;
    }

private:
    std::vector<int> current;
    std::vector<int> original;
};

int main()
{
    std::vector<int> vec = { 1, 2, 3 };
    Solution ss(vec);
    ss.shuffle();

    return 0;
}
