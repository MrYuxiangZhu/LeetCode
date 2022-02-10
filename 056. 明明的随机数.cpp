// 056. 明明的随机数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n = 0, temp = 0;
    while (cin >> n)
    {
        set<int> nums;
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            nums.emplace(temp);
        }

        for (auto& iter : nums)
        {
            cout << iter << endl;
        }
    }
    return 0;
}
