/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    
    m := make(map[byte]int, 0)
    for i := 0; i < len(s); i++ {
        m[s[i]]++
        m[t[i]]--
    }

    for _, v := range m {
        if v != 0 {
            return false
        }
    }

    return true
}
