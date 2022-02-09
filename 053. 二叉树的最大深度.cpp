// 053. 二叉树的最大深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if (!root)
        {
            return 0;
        }

        int lchild = maxDepth(root->left) + 1;
        int rchild = maxDepth(root->right) + 1;
        return std::max(lchild, rchild);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
