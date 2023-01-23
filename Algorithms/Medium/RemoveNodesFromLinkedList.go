package removeNodesFromLinkedList

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func removeNodes(head *ListNode) *ListNode {
    head = reverse(head)
    save := head

    for head != nil && head.Next != nil {
        if head.Next.Val < head.Val {
            head.Next = head.Next.Next
            continue
        }
        head = head.Next
    }

    return reverse(save)
}

func reverse(head *ListNode) *ListNode {
    var next *ListNode = nil
    var prev *ListNode = nil

    for head != nil {
        next = head.Next
        head.Next = prev
        prev = head
        head = next
    }

    return prev
}