/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

type pair struct {
    key int
    cnt int
}

type pairm []pair

func (a pairm) Len() int           { return len(a) }
func (a pairm) Less(i, j int) bool { return a[i].cnt > a[j].cnt }
func (a pairm) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

func topKFrequent(nums []int, k int) []int {
    m := make(map[int]int, len(nums)/2)

    for _, val := range nums {
        m[val]++
    }

    arr := make([]pair, len(m))
    for k,v := range m {
        arr = append(arr,pair{key:k, cnt:v})
    }

    sort.Sort(pairm(arr))

    out := make([]int,0)

    for i :=0; i< k; i++ {
        out = append(out, arr[i].key)
    }

    return out
}
