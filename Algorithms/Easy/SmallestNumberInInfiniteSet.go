/*
2336. Smallest Number in Infinite Set

You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
*/

type SmallestInfiniteSet struct {
    currNum int
    set map[int]int
}


func Constructor() SmallestInfiniteSet {
    return SmallestInfiniteSet{0, make(map[int]int, 0)}
}


func (this *SmallestInfiniteSet) PopSmallest() int {
    if len(this.set) != 0 {
        keys := make([]int, 0, len(this.set))
        for k := range this.set {
            keys = append(keys, k)
        }
        sort.Ints(keys)

        value:= keys[0]
        delete(this.set, keys[0])
        return value
    }
    this.currNum++
    return this.currNum
}


func (this *SmallestInfiniteSet) AddBack(num int)  {
    if num <= this.currNum {
        if _, ok := this.set[num]; ok {
            delete(this.set, num)
        }
        this.set[num]++
    }
}


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.PopSmallest();
 * obj.AddBack(num);
 */
