// 最后一个单词的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	int lengthOfLastWord(string s) 
	{
		int n = s.size() - 1;
		while (s[n] == ' ')
		{
			s = s.substr(0, n);
			n = s.size() - 1;
		}

		int len = 0;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (s[i] == ' ')
			{
				break;
			}

			len++;
		}

		return len;
	}
};

int main()
{
	Solution ss;
	std::cout << ss.lengthOfLastWord("a ") << std::endl;
	return 0;
}
