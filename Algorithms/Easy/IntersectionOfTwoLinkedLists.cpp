/*
160. Intersection of Two Linked Lists

Given the heads of two singly linked-lists headA and headB, return the node
at which the two lists intersect. If the two linked lists have no intersection at all, return null.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        std::unordered_map<ListNode*,int> uMap{};

        for (auto ptr = headA; ptr; ptr = ptr->next)
        {
            uMap[ptr]++;
        }

        for(auto ptr = headB; ptr; ptr = ptr->next)
        {
            if(uMap.count(ptr))
                return ptr;
        }

        return nullptr;


        // Brut force
        // ListNode* newHeadA = headA;
        // ListNode* newHeadB = headB;
        // while(newHeadA)
        // {
        //     while(newHeadB)
        //     {
        //         if (newHeadB == newHeadA)
        //             return newHeadA;
        //         newHeadB = newHeadB->next;
        //     }
        //     newHeadB = headB;
        //     newHeadA = newHeadA->next;
        // }

        // return nullptr;      
    }
};
