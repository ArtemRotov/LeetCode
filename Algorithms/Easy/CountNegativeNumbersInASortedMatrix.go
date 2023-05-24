/*
1351. Count Negative Numbers in a Sorted Matrix

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
*/

func countNegatives(grid [][]int) int {

	result := 0

	left := 0
	right := len(grid[0]) - 1
	sleft := len(grid[0])

	for i := 0; i < len(grid); i++ {

		for left < right {
			mid := (left + right) / 2
			if grid[i][mid] >= 0 {
				left = mid + 1
			} else {
				right = mid
			}
		}

		if grid[i][left] < 0 {
			result += len(grid[i]) - left
			right = left - 1
			sleft = left
			left = 0

		} else {
			result += len(grid[i]) - sleft
			sleft = len(grid[i])
			left = 0
			right = len(grid[0]) - 1
		}
	}

	return result
}
