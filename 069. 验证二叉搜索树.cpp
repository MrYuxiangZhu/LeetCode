// 069. 验证二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * Definition for a binary tree node.
 */

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        vector<int> nums;
        inorder(root, nums);
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
            {
                return false;
            }
        }

        return true;
    }
private:
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if (nullptr == root) return;
        inorder(root->left, nums);
        nums.emplace_back(root->val);
        inorder(root->right, nums);
    }
};

int main()
{
    
}
