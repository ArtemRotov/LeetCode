/*
203. Remove Linked List Elements

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 
func removeElements(head *ListNode, val int) *ListNode {
    headSave := head
    for head != nil {
        if head.Val == val {
            headSave = headSave.Next
            head = headSave
            continue
        }

        for head.Next != nil && head.Next.Val == val {
            head.Next = head.Next.Next

        }
        
        head = head.Next
    }

    return headSave
}
