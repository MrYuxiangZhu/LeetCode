// 最长回文子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    static string LongestPalindrome(string s) 
    {

        if (s.size() < 2)
        {
            return s;
        }

        int start = 0;
        int max_len = 1;

        std::vector<std::vector<int>> DP(s.size(), std::vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); ++i)
        {
            DP[i][i] = 1;
        }

        for (int k = 1; k < s.size(); ++k)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                int j = i + k;
                if (j >= s.size())
                {
                    break;
                }

                if (s[i] != s[j])
                {
                    continue;
                }
                else
                {
                    DP[i][j] = j - i + 1 >= 3 ? DP[i + 1][j - 1] : 1;
                }

                if (DP[i][j] && j - i + 1 > max_len)
                {
                    start = i;
                    max_len = j - i + 1;
                }
            }
        }

        return s.substr(start, max_len);
    }
};

int main()
{
    std::cout << Solution::LongestPalindrome("ab") << std::endl;
    return 0;
}
