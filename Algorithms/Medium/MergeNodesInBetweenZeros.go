/*
2181. Merge Nodes in Between Zeros

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeNodes(head *ListNode) *ListNode {
    
    var headSave *ListNode = nil
    var newHead *ListNode = nil
    sum := 0
    for head != nil {
        if head.Val == 0 && sum == 0 {
            head = head.Next
            continue
        }

        if head.Val == 0 {
            head.Val = sum
            if headSave == nil {
                headSave = head
                newHead = headSave
                sum = 0
                head = head.Next
                continue
            }
            newHead.Next = head
            newHead = newHead.Next
            sum = 0
            head = head.Next
            continue
        }

        sum += head.Val
        head = head.Next
    }

    return headSave
}
