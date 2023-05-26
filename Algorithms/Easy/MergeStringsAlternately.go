/*
1768. Merge Strings Alternately
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.
*/


func mergeAlternately(word1 string, word2 string) string {
    str := ""

	for i, j := 0, 0; i < len(word1) || j < len(word2); i, j = i+1, j+1 {
		if i < len(word1){
			str += string(word1[i])
		}

		if j < len(word2){
			str += string(word2[j])
		}
	}

	return str
}
