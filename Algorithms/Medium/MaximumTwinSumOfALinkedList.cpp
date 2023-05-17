/*
2130. Maximum Twin Sum of a Linked List

In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list 
is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. 
These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
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
    int pairSum(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        int max = 0;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(slow)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        slow = prev;

        while(slow)
        {
            max = std::max(max, head->val + slow->val);
            head = head->next;
            slow = slow->next;
        }

        return max;
    }
    
    
    // Simple but slow
    // int pairSum(ListNode* head) 
    // {
        
    //     std::vector<int> v{};

    //     while(head)
    //     {
    //         v.push_back(head->val);
    //         head = head->next;
    //     }

    //     int max = 0;

    //     for (int i = 0; i < v.size()/2; i++)
    //     {
    //         max = std::max(max, v[i] + v[v.size() - i - 1]);
    //     }

    //     return max;
    // }
};
