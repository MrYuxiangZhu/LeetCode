// 067. 相同的树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <deque>

using namespace std;

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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (nullptr == p && nullptr == q)
        {
            return true;
        }
        else if (nullptr == p || nullptr == q)
        {
            return false;
        }
        else if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

class Solution1
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (nullptr == p && nullptr == q)
        {
            return true;
        }
        else if (nullptr == p || nullptr == q)
        {
            return false;
        }

        deque<TreeNode*> deque1, deque2;
        deque1.emplace_back(p);
        deque2.emplace_back(q);

        while (!deque1.empty() && !deque2.empty())
        {
            auto top1 = deque1.front();
            auto top2 = deque2.front();
            deque1.pop_front();
            deque2.pop_front();

            if (top1->val != top2->val)
            {
                return false;
            }

            auto left1 = top1->left;
            auto right1 = top1->right;
            auto left2 = top2->left;
            auto right2 = top2->right;

            if ((nullptr == left1) ^ (nullptr == left2))
            {
                return false;
            }

            if ((nullptr == right1) ^ (nullptr == right2))
            {
                return false;
            }

            if (nullptr != left1)
            {
                deque1.emplace_back(left1);
            }

            if (nullptr != right1)
            {
                deque1.emplace_back(right1);
            }

            if (nullptr != left2)
            {
                deque2.emplace_back(left2);
            }

            if (nullptr != right2)
            {
                deque2.emplace_back(right2);
            }

        }

        return deque1.empty() && deque2.empty();
    }
};

int main()
{
    Solution1 ss;

    TreeNode* tree1 = new TreeNode(1);
    tree1->left = nullptr;
    tree1->right = new TreeNode(1);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = nullptr;
    tree2->right = new TreeNode(1);

    std::cout << ss.isSameTree(tree1, tree2) << std::endl;

    delete tree1->right;
    delete tree2->right;
    delete tree1;
    delete tree2;

    return 0;
}