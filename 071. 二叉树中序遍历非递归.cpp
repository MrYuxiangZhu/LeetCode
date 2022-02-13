﻿// 071. 二叉树中序遍历非递归.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    void inOrderTraverse(TreeNode* root, vector<int>& nums)
    {
        TreeNode* top = root;
        stack<TreeNode*> sta;
        while (top || !sta.empty())
        {
            if (top)
            {
                sta.push(top);
                top = top->left;
            }
            else
            {
                top = sta.top();
                sta.pop();
                nums.emplace_back(top->val);
                top = top->right;
            }
        }
    }
};

int main()
{
    return 0;
}

