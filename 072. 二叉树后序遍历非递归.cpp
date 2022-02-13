// 072. 二叉树后序遍历非递归.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void proOrderTraverse(TreeNode* root, vector<int>& nums)
    {
		std::stack<TreeNode*> sta;
		TreeNode* top = root;
		TreeNode* vis = nullptr;/*临时变量，记录上一个访问到的结点，因为从右边访问根结点，
							   必定是右子树已经遍历结束，此时上一个访问的结点必定是右子树的根结点*/
		while (top || !sta.empty())
		{
			if (top)
			{
				sta.push(top);
				top = top->left;
			}
			else
			{
				top = sta.top();//只读取根结点，不对栈内结点进行操作
				if (top->right && top->right != vis)//没有对右子树进行操作过
				{
					top = top->right;
					sta.push(top);
					top = top->left;
				}
				else
				{
					sta.pop();
					nums.emplace_back(top->val);//对top进行访问，可以进行打印等操作
					vis = top;//记录当前访问的是p结点
					top = nullptr;//把p置空，进入下一次循环，直到栈内无元素，且p为空时遍历完成
				}
			}
		}
    }
};

int main()
{
    return 0;
}