// 有效的括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    static bool IsValid(string s) 
    {
        if (s.size() % 2 == 1) return false;

        std::stack<char> sta;
        std::unordered_map<char, char> mmap =
        {
            { ')', '(' },
            { '}', '{' },
            { ']', '[' }
        };

        for (auto iter : s)
        {
            if (mmap.find(iter) != mmap.end())
            {
                if (sta.empty() || sta.top() != mmap[iter])
                {
                    return false;
                }

                sta.pop();
            }
            else
            {
                sta.push(iter);
            }
        }

        return sta.empty();
    }
};

int main()
{
    std::cout << Solution::IsValid("(") << std::endl;
    std::cout << Solution::IsValid("({})") << std::endl;
    return 0;
}
