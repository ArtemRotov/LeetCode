/*
2487. Remove Nodes From Linked List

You are given the head of a linked list.

Remove every node which has a node with a strictly greater value anywhere to the right side of it.

Return the head of the modified linked list.
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
    ListNode* removeNodes(ListNode* head)
    {
        head = reverse(head);
        ListNode* save = head;
        while(head && head->next)
        {
            if (head->next->val < head->val)
            {
                head->next = head->next->next;
                continue;
            }

            head = head->next;
        }
        return reverse(save);
    }

private:
    ListNode* reverse(ListNode* head)
    {
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while(head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
