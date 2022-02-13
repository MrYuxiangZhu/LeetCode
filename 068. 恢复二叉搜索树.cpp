// 068. 恢复二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    void recoverTree(TreeNode* root) 
    {
        vector<int> nums;
        inorder(root, nums);
        pair<int, int> swapped = findTwoSwapped(nums);
        recover(root, swapped);
    }
private:
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if (nullptr == root) return;
        inorder(root->left, nums);
        nums.emplace_back(root->val);
        inorder(root->right, nums);
    }

    pair<int, int> findTwoSwapped(vector<int>& nums)
    {
        int first = -1;
        int second = -1;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                second = i + 1;
                if (first == -1)
                {
                    first = i;
                }
                else
                {
                    break;
                }
            }
        }

        return { nums[first], nums[second] };
    }

    void recover(TreeNode* root, pair<int, int>& swapped)
    {
        if (nullptr == root) return;
        recover(root->left, swapped);
        if (root->val == swapped.first || root->val == swapped.second)
        {
            root->val = root->val == swapped.first ? swapped.second : swapped.first;
        }
        recover(root->right, swapped);
    }
};

int main()
{
    return 0;
}
