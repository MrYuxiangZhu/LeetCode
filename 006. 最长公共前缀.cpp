// 最长公共前缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    static string LongestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0) return string();

        string str;
        bool equal = true;
        int len = strs[0].size();
        for (auto iter : strs)
        {
            if (iter.size() < len)
            {
                len = iter.size();
            }
        }

        for (int j = 0; j < len; ++j)
        {
            equal = true;
            for (int i = 0; i < strs.size() - 1; ++i)
            {
                if (strs[i][j] != strs[i + 1][j])
                {
                    equal = false;
                    break;
                }
            }

            if (equal)
            {
                str += strs[0][j];
            }
            else
            {
                break;
            }
        }

        return str;
    }
};

int main()
{
    std::vector<string> strs = { "crc","cic","cac" };
    std::cout << Solution::LongestCommonPrefix(strs) << std::endl;
    return 0;
}
