// 合并两个有序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if (NULL == list1) return list2;
        if (NULL == list2) return list1;

        ListNode* head = new ListNode(-1);
        ListNode* clist = head;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                clist->next = list1;
                list1 = list1->next;
            }
            else
            {
                clist->next = list2;
                list2 = list2->next;
            }

            clist = clist->next;
        }

        clist->next = list1 ? list1 : list2;

        return head->next;
    }

    static ListNode* MergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (NULL == list1)
        {
            return list2;
        }
        else if (NULL == list2) 
        { 
            return list1; 
        }
        else if (list1->val < list2->val)
        {
            list1->next = MergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = MergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    static ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) 
    {
        if (l1 == nullptr) 
        {
            return l2;
        }
        else if (l2 == nullptr) 
        {
            return l1;
        }
        else if (l1->val < l2->val) 
        {
            l1->next = mergeTwoLists2(l1->next, l2);
            return l1;
        }
        else 
        {
            l2->next = mergeTwoLists2(l1, l2->next);
            return l2;
        }
    }
};

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode* list3 = new ListNode(7);
    list3->next = new ListNode(10);
    list3->next->next = new ListNode(8);

    ListNode* merge = Solution::mergeTwoLists2(list1, list3);

    while (merge != nullptr) 
    {
        std::cout << merge->val << ",";
        merge = merge->next;
    }
}
