/*
110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 
func isBalanced(root *TreeNode) bool {
    if (root == nil) {
        return true
    }
    if (helper(root) == -1) {
        return false
    }

    return true
}

func helper(root *TreeNode) int {
    if (root == nil){
        return 0
    }

    leftDepth := helper(root.Left)
    rightDepth := helper(root.Right)

    if leftDepth == -1 || rightDepth == -1 || abs(leftDepth,rightDepth) > 1 {
        return -1
    }

    return max(leftDepth, rightDepth) + 1
}

func max(a,b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func abs(a,b int) int {
    if a < b {
        return b - a
    } else {
        return a - b
    }
}
