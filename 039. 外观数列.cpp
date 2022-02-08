// 外观数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
		string prev = "1";
		for (int i = 2; i <= n; ++i)
		{
			string curr = "";
			int start = 0;
			int pos = 0;
			while (pos < prev.size())
			{
				while (pos < prev.size() && prev[pos] == prev[start])
				{
					pos++;
				}

				curr += to_string(pos - start) + prev[start];
				start = pos;
			}

			prev = curr;
		}

		return prev;
    }
};

int main()
{
	Solution ss;
	std::cout << ss.countAndSay(4) << std::endl;
	return 0;
}