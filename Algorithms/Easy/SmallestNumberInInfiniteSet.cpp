/*
2336. Smallest Number in Infinite Set

You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
*/

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() 
    {
        
    }
    
    int popSmallest() 
    {
        if (s.size())
        {
            int n = *(s.begin());
            s.erase(s.begin());
            return n;
        }

        return ++cnum;    
    }
    
    void addBack(int num) 
    {
        if (num <= cnum)
            s.insert(num);
    }

private:
    std::set<int> s {};
    int cnum = 0;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
