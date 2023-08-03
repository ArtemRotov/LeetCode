/*
868. Binary Gap
Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.

Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For example, the two 1's in "1001" have a distance of 3.
*/

func binaryGap(n int) int {
    
    bin := make([]int, 0)

    for n > 0 {
        bin = append(bin, n & 1)
        n = n >> 1
    }

    max := 0
    for i := 0; i < len(bin); i++ {
        if bin[i] == 0 {
            continue
        }
        
        haveOne := false
        vn:
        for j := i + 1; j < len(bin); j++ {
            if bin[j] == 1 && haveOne {
                break vn
            }
            if bin[j] == 1 {
                haveOne = true
                if j - i > max {
                    max = j - i
                }
            }
        }
    }

    return max
}
