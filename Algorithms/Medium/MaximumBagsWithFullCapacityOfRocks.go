/*
2279. Maximum Bags With Full Capacity of Rocks

You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.

Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.
*/

func maximumBags(capacity []int, rocks []int, k int) int {
    
    sl := make([]int, 0, len(rocks))

    for i := 0; i < len(rocks); i++ {
        sl = append(sl, capacity[i] - rocks[i]) 
    }
    sort.Ints(sl)

    i:= 0

    for ; i < len(sl) && k > 0 && k >= sl[i]; i++ {
        k -= sl[i]
    }

    return i
}
