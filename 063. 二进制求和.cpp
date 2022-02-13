// 063. 二进制求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        string str;
        int carry = 0;
        int len = std::max(a.size(), b.size());
        for (int i = 0; i < len; ++i)
        {
            int b1 = i < a.size() ? (a[i] == '1') : 0;
            int b2 = i < b.size() ? (b[i] == '1') : 0;
            int sum = b1 + b2 + carry;
            str += sum % 2 == 0 ? '0' : '1';
            carry = sum / 2;
        }

        if (carry > 0)
        {
            str += '1';
        }

        std::reverse(str.begin(), str.end());

        return str;
    }
};

int main()
{
    Solution ss;
    std::cout << ss.addBinary("111", "11") << std::endl;
    return 0;
}
