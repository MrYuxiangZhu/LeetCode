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
        stack<int> sta;
        sta.push(-1);
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                sta.push(i); 
            }
            else
            {
                sta.pop();
                if (sta.empty())
                {
                    sta.push(i);
                }
                else
                {
                    longest = std::max(longest, i - sta.top());
                }
            }
        }

        return longest;
    }
};

int main()
{
    Solution ss;
    std::cout << ss.longestValidParentheses("())((())") << std::endl;
    return 0;
}
