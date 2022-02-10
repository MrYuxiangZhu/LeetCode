// 057. 字符串分隔.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;

    while (getline(cin, str1))
    {
        while (str1.size() > 8)
        {
            cout << str1.substr(0, 8) << endl;
            str1 = str1.substr(8, str1.size() - 8);
        }

        for (int i = str1.size(); i < 8; ++i)
        {
            str1 += '0';
        }

        cout << str1 << endl;
    }
    
    return 0;
}
