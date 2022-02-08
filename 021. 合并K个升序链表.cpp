// 合并K个升序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    ListNode* mergeTwo(ListNode* List1, ListNode* List2)
    {
        if (nullptr == List1) return List2;
        if (nullptr == List2) return List1;

        if (List1->val < List2->val)
        {
            List1->next = mergeTwo(List1->next, List2);
            return List1;
        }

        List2->next = mergeTwo(List1, List2->next);
        return List2;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* ListR = nullptr;
        for (auto iter : lists)
        {
            ListR = mergeTwo(ListR, iter);
        }

        return ListR;
    }
};

int main()
{
    Solution ss;
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode* list3 = new ListNode(7);
    list3->next = new ListNode(10);
    list3->next->next = new ListNode(8);

    vector<ListNode*> lists;
    lists.emplace_back(list1);
    //lists.emplace_back(list2);
    lists.emplace_back(list3);

    ListNode* merge = ss.mergeKLists(lists);

    while (merge != nullptr)
    {
        std::cout << merge->val << ",";
        merge = merge->next;
    }
}
