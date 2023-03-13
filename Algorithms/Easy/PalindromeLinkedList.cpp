/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.
 
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
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        prev = slow;
        slow = slow->next;
        prev->next = nullptr;
        
        while (slow)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        slow = prev;
        fast = head;

        while (slow)
        {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};
