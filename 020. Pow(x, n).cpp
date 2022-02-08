// Pow(x, n).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Solution 
{
public:
	double myPow(double x, int n) 
	{
		if (x == 1)
		{
			return 1;
		}

		return n >= 0 ? quick(x, n) : 1.0 / quick(x, n);
	}
private:
	double quick(double x, long long n)
	{
		if (n == 0)
		{
			return 1.0;
		}

		double y = quick(x, n / 2);
		return n % 2 == 0 ? y * y : y * y * x;
	}
};

int main()
{
	Solution ss;
	std::cout << ss.myPow(1, 2147483647) << std::endl;
	return 0;
}
