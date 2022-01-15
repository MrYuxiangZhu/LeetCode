// 两两交换链表中的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

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
    static ListNode* swapPairs(ListNode* head) 
    {
        ListNode* phead = new ListNode(-1);
        ListNode* clist = head;
        head = phead;

        while (clist && clist->next)
        {
            head->next = clist->next;
            ListNode* start = head;
            ListNode* tail = start->next;
            start->next = tail->next;
            tail->next = start;
            clist = start->next;
            head = start;
        }

        head->next = clist;

        return phead->next;
    }

    static ListNode* swapPairs1(ListNode* head)
    {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        ListNode* phead = head->next;
        head->next = swapPairs(phead->next);
        phead->next = head;
        return phead;
    }

    static ListNode* swapPairs2(ListNode* head)
    {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        ListNode* phead = new ListNode(-1);
        phead->next = head->next;
        head->next = swapPairs2(phead->next->next);
        phead->next->next = head;

        return phead->next;
    }
};

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);
    list1->next->next->next->next->next = new ListNode(6);
    ListNode* merge = Solution::swapPairs2(list1);

    while (merge != nullptr)
    {
        std::cout << merge->val << ",";
        merge = merge->next;
    }

    return 0;
}
