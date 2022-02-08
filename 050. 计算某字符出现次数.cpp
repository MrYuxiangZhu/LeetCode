// 050. 计算某字符出现次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int LetterCount(string str, char c)
    {
        unordered_map<char, int> mmap;
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        if (c >= 'A' && c <= 'Z')
        {
            c += 32;
        }

        for (auto& it : str)
        {
            if (mmap.find(it) != mmap.end())
            {
                mmap[it] += 1;
            }
            else
            {
                mmap[it] = 1;
            }
        }

        return mmap[c];
    }
};

int main()
{
    Solution ss;
    string str;
    char c;
    getline(cin, str);
    c = getchar();
    std::cout << ss.LetterCount(str, c) << std::endl;
    return 0;
}
