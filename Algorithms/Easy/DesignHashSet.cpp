/*
705. Design HashSet

Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
 
class MyHashSet {
public:
    MyHashSet() : cap(2), len(0), factor(0.7), hash_table(cap)
    {

    }

    void add(int key)
    {
        if (!contains(key))
        {
            int h = hash(key);

            hash_table[h].push_back(key);
            len++;

            if (len >= cap * factor) rehash();
        }
    }

    void remove(int key)
    {
        if (contains(key))
        {
            int h = hash(key);
            hash_table[h].remove(key);
            len--;
        }
    }

    bool contains(int key)
    {
        int h = hash(key);

        return std::find(hash_table[h].begin(), hash_table[h].end(), key) != hash_table[h].end();
    }

private:
    int cap;
    int len;
    float factor;

    std::vector<std::list<int>> hash_table;

    int hash(int key)
    {
        return key % cap;
    }

    void rehash()
    {
        cap = cap * 2;
        len = 0;

        std::vector<std::list<int>> save_table = hash_table;
        hash_table = std::vector<std::list<int>>(cap);



        for (std::list<int> &l : save_table)
        {
            for (int v : l)
            {
                add(v);
            }
        }
    }
};


