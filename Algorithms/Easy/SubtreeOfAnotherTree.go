/*
572. Subtree of Another Tree

Given the roots of two binary trees root and subRoot, return true if there is a subtree 
of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of 
this node's descendants. The tree tree could also be considered as a subtree of itself.

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 
func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
    
    result := isSameTree(root, subRoot)
    
    if root == nil || result == true {
        return result
    }

    return isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
}

func isSameTree(root, subRoot *TreeNode) bool {
    if root == nil && subRoot == nil {
        return true
    }

    if (root == nil && subRoot != nil) || (root != nil && subRoot == nil) {
        return false
    }

    if root.Val != subRoot.Val {
        return false
    }

    return isSameTree(root.Left, subRoot.Left) && isSameTree(root.Right, subRoot.Right) 
}
