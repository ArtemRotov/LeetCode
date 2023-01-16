/*
206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.
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

    //Recursive solution
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next)
            return head;

        ListNode *node = reverseList(head->next);
        head ->next->next = head;
        head->next = NULL;
        return node;
    }

    // Iterative solution
    ListNode* reverseList(ListNode* head)
    {
        ListNode *nextNode = nullptr;
        ListNode *prevNode = nullptr;

        while (head)
        {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }

        return prevNode;
    }

    // Vector solution (O(n^2))
    ListNode* reverseList(ListNode* head)
    {
        std::vector<ListNode*> vec {};
        while (head)
        {
            vec.push_back(head);
            head = head->next;
        }

        for (int i = vec.size() - 1; i > 0; --i)
            vec[i]->next = vec[i - 1];

        if (!vec.empty())
            vec[0]->next = nullptr;

        return vec.empty() ? nullptr : vec[vec.size() - 1];
    }
};
