92. Reverse Linked List II

Given the head of a singly linked list and two integers left and
right where left <= right, reverse the nodes of the list from position
left to position right, and return the reversed list.

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
    ListNode* reverse(ListNode* head, int stop)
    {
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* headSave = head;
        int cnt = 0;
        while(head && cnt != stop)
        {  
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            cnt++;
        }
        if (headSave && cnt == stop)
            headSave->next = head;

        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* savebegin = head;
        ListNode* save = nullptr;
        int cnt = 1;
        while(head && cnt != left)
        {
            save = head;
            head = head->next;
            cnt++;
        }

        if (!head || !save)
            return reverse(savebegin, right - left + 1);
        
        if (save)
            save->next = reverse(head, right - left + 1);
        
        return savebegin;
    }
};
