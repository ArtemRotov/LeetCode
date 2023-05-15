/*
1721. Swapping Nodes in a Linked List

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from 
the beginning and the kth node from the end (the list is 1-indexed).

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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* ptr1 = nullptr;
        ListNode* ptr2 = nullptr;

        for (auto p = head; p; p = p->next)
        {
            ptr2 = (ptr2 == nullptr) ? nullptr : ptr2->next;
            
            if (--k == 0)
            {
                ptr2 = head;
                ptr1 = p;
            }
        }

        std::swap(ptr1->val, ptr2->val);
        
        return head;
    }

    // Hash solution - slowly
    //     ListNode* swapNodes(ListNode* head, int k) 
    // {
    //     std::unordered_map<int, ListNode*> hash{};

    //     for (int i = 1; head ; i++, head = head->next)
    //     {
    //         hash[i] = head;
    //     }

    //     int save = hash[k]->val;
    //     hash[k]->val = hash[hash.size() - k + 1]->val;
    //     hash[hash.size() - k + 1]->val = save;

    //     return hash[1];
    // }
};
