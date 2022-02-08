// 052. 最长有效括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>

using namespace std;

class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        int longest = 0;
        stack<char> sta;
        for (auto& it : s)
        {
            if (it == ')')
            {
                if (sta.empty())
                {
                    continue;
                }

                if (sta.top() == '(')
                {
                    longest += 2;
                }

                sta.pop();
            }
            else
            {
                sta.push(it);
            }
        }

        return longest;
    }
};

int main()
{
    Solution ss;
    std::cout << ss.longestValidParentheses("()(()") << std::endl;
    return 0;
}
