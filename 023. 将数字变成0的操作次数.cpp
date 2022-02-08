// 将数字变成0的操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Solution 
{
public:
    int numberOfSteps(int num) 
    {
        int count = 0;
        while (num > 0)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                num -= 1;
            }
            count++;
        }

        return count;
    }
};

int main()
{
    Solution ss;
    std::cout << ss.numberOfSteps(8) << std::endl;
    return 0;
}
