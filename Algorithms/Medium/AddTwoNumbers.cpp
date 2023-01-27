/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits
are stored in reverse order, and each of their nodes contains a single digit. Add the two
numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* result = new ListNode();
        ListNode* ret = result;
        int save = 0;

        while(l1 || l2)
        {
            int sum = save;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;

            result->next = new ListNode(sum % 10);

            save = sum / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            result = result->next;
        }

        if (save) result->next = new ListNode(save % 10);

        return ret->next;
    }
};
