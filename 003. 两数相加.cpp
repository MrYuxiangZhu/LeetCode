// 两数相加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

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
    static ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int sum = 0;
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            sum = n1 + n2 + carry;
            carry = sum / 10;
            if (nullptr == head)
            {
                head = tail = new ListNode(sum % 10);
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }

            if (l1)
            {
                l1 = l1->next;
            }

            if (l2)
            {
                l2 = l2->next;
            }
        }

        if (carry > 0)
        {
            tail->next = new ListNode(1);
        }

        return head;
    }

    static ListNode* CreateList(ListNode* list, int num)
    {
        if (nullptr == list)
        {
            list = new ListNode(num);
        }
        else
        {
            ListNode* node = new ListNode(num);
            node->next = list;
            list = node;
        }

        return list;
    }
};

int main()
{
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
    ListNode* l3 = nullptr;
    l1 = Solution::CreateList(l1, 3);
    l1 = Solution::CreateList(l1, 4);
    l1 = Solution::CreateList(l1, 2);
    l2 = Solution::CreateList(l2, 4);
    l2 = Solution::CreateList(l2, 6);
    l2 = Solution::CreateList(l2, 5);
    l3 = Solution::AddTwoNumbers(l1, l2);
    return 0;
}
