// 076. 反转链表 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        int count = 1;
        vector<int> nums;
        ListNode* cur = head;
        while (cur)
        {
            if (count >= left && count <= right)
            {
                nums.emplace_back(cur->val);
            }

            cur = cur->next;
            count++;
        }

        reverse(nums.begin(), nums.end());

        count = 1;
        cur = head;

        while (cur)
        {
            if (count >= left && count <= right)
            {
                cur->val = nums[count - left];
            }

            cur = cur->next;
            count++;
        }

        return head;
    }
};

int main()
{
    return 0;
}
