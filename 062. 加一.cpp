// 062. 加一.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            int sum = carry + digits[i];
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0)
        {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

int main()
{
    Solution ss;
    vector<int> nums = { 1, 2, 3 };
    nums = ss.plusOne(nums);
    return 0;
}
