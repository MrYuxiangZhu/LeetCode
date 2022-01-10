// 无重复字符的最长子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    static int LengthOfLongestSubstring(string s) 
    {
        std::unordered_set<char> backup;
        int max_len = 0;
        int left = 0;
        int right = 0;
        for (; right < s.size();)
        {
            if (backup.find(s[right]) == backup.end())
            {
                backup.insert(s[right++]);
                max_len = std::max((int)backup.size(), max_len);
            }
            else
            {
                backup.erase(s[left++]);
            }
        }

        return max_len;
    }
};

int main()
{
    string str = "aab";
    std::cout << Solution::LengthOfLongestSubstring(str) << std::endl;
    return 0;
}