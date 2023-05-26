/*1071. Greatest Common Divisor of Strings

For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
*/

func gcdOfStrings(str1 string, str2 string) string {
	i := 0
	for ; i < len(str1) && i < len(str2); i++ {
		if str1[i] != str2[i] {
			break
		}
	}
	
	for i > 0 && (len(str1)%i != 0 || len(str2)%i != 0) {
		i--
	}
	str := str1[:i]

	str1 = strings.ReplaceAll(str1, str, "")
	if len(str1) > 0 {
		return ""
	}
	str2 = strings.ReplaceAll(str2, str, "")
	if len(str2) > 0 {
		return ""
	}

	return str
}	
