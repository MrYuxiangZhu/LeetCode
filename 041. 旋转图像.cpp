// 旋转图像.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int>>& matrix) 
	{
		vector<vector<int>> ans = matrix;
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0, k = matrix[0].size() - 1; j < matrix[0].size() && k >= 0; ++j, --k)
			{
				ans[i][j] = matrix[k][i];
			}
		}
		matrix = ans;
	}
};

int main()
{
	Solution ss;
	vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	ss.rotate(matrix);
	return 0;
}
