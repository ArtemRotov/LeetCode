/*
821. Shortest Distance to a Character

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.
*/

func shortestToChar(s string, c byte) []int {
	res := make([]int, 0, len(s))
	m := make([]int, 0)

	for i, ch := range s {
		if ch == rune(c) {
			m = append(m, i)
		}
	}

	for i := range s {
		min := 1000000
		for _, v := range m {
			if abs(i-v) < min {
				min = abs(i - v)
			}
		}
		res = append(res, min)
	}
	return res
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
