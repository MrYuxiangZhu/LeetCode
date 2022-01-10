// 回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    static bool IsPalindrome(int x) 
    {
        std::string str = to_string(x);
        int i = 0;
        int j = str.size() - 1;
        while (i <= j)
        {
            if (str[i] == str[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    std::cout << Solution::IsPalindrome(121) << std::endl;

    return 0;
}