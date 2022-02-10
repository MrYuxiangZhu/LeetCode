// 058. 进制转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        int num = 0;
        int pos = str.find('x');
        for (int i = pos + 1; i < str.size(); ++i)
        {
            int temp = 0;
            if (str[i] >= 'A' && str[i] <= 'F')
            {
                temp = 10 + (str[i] - 'A');
            }
            else
            {
                temp = str[i] - '0';
            }
            num = num * 16 + temp;
        }
        cout << num << endl;
    }

    return 0;
}
