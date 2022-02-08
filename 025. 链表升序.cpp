// 链表升序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution
{
public:
    static ListNode* sort(ListNode* head)
    {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        if (head->val > head->next->val)
        {
            ListNode* phead = head->next;
            head->next = head->next->next;
            phead->next = sort(head);
            return phead;
        }
        else
        {
            head->next = sort(head->next);
            return head;
        }
    }
};

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);
    list1->next->next->next = new ListNode(10);
    list1->next->next->next->next = new ListNode(4);

    ListNode* list = Solution::sort(list1);

    while (list != nullptr)
    {
        std::cout << list->val << ",";
        list = list->next;
    }

    return 0;
}
