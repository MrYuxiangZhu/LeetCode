// 数字翻译成字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Solution 
{
public:
    int translateNum(int num) 
    {
        if (num == 0) return 1;
        return f(num);
    }

    int f(int num) 
    {
        if (num < 10) 
        {
            return 1;
        }
        if (num % 100 < 26 && num % 100 > 9) 
        {
            return f(num / 10) + f(num / 100);
        }
        else 
        {
            return f(num / 10);
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
