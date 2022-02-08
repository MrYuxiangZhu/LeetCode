// 049. 字符串最后一个单词的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        int size = s.size();
        while (s[size - 1] == ' ')
        {
            s = s.substr(0, size - 1);
            size = s.size();
        }

        int length = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == ' ')
            {
                break;
            }
            length++;
        }

        return length;
    }
};

int main()
{
    Solution ss;
    std::cout << ss.lengthOfLastWord("hello world  ") << std::endl;
    return 0;
}
