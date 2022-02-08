// 实现strStr().cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        if (needle == "") return 0;
        return haystack.find(needle);
    }

    int strStr2(string haystack, string needle)
    {
        int m = haystack.size();
        int n = needle.size();
        bool flag = true;

        for (int i = 0; i + n < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution ss;
    std::string haystack = "aaaaa";
    std::string needle = "bba";
    std::cout << ss.strStr2(haystack, needle) << std::endl;
    return 0;
}