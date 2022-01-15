// 删除链表的倒数第 N 个结点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


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
    static ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;

        for (int i = 0; i < n; ++i) 
        {
            first = first->next;
        }

        while (first) 
        {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution::removeNthFromEnd(head, 1);
}
