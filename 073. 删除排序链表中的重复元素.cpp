// 073. 删除排序链表中的重复元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * Definition for singly-linked list.
 */

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (!head) 
        {
            return head;
        }

        ListNode* cur = head;
        while (cur->next)
        {
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }

        return head;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
