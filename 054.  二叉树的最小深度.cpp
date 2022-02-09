// 054.  二叉树的最小深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

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
    int minDepth(TreeNode* root) 
    {
        if (nullptr == root)
        {
            return 0;
        }

        if (nullptr == root->left && nullptr == root->right)
        {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left)
        {
            min_depth = std::min(minDepth(root->left), min_depth);
        }

        if (root->right)
        {
            min_depth = std::min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};

int main()
{
    return 0;
}
