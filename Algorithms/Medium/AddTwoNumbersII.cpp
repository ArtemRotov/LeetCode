/*
445. Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
        l1 = reverse(l1);
        ListNode* s = l1;   
        l2 = reverse(l2);   

        while (l1 || l2)
        {
            static int save = 0;
            int sum = 0;

            sum += save;
            save = 0;
            sum += l1 ? l1->val : 0;
            sum += l2 ? l2->val : 0;

            if (sum > 9)
            {
                save = 1;
                sum -= 10;
            }

            l1->val = sum;

            if ( (l1 && l1->next) || (l2 && l2->next) || save)
            {
                if (!l1->next) l1->next = new ListNode();
            }

            l1 = l1->next;
            if (l2) l2 = l2->next;            
        }

        return reverse(s);
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

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
