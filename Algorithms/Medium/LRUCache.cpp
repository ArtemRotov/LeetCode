/*
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

class LRUCache {
public:
    LRUCache(int capacity)
    : m_cap(capacity)
    , m_list()
    , m_map()
    {

    }
    
    int get(int key) 
    {
        auto it = m_map.find( key );
        if ( it == m_map.end() ) return -1;

        m_list.splice(m_list.begin(), m_list, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) 
    {
        auto it = m_map.find( key );
        if ( it != m_map.end() )
        {
            m_list.splice(m_list.begin(), m_list, it->second);
            it->second->second = value;
            return;
        }
        if ( m_map.size() == m_cap )
        {
            int del = m_list.back().first;
            m_list.pop_back();
            m_map.erase(del);
        }
        m_list.emplace_front(key, value);
        m_map[key] = m_list.begin();
    }

private:
    //std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_map;
    unordered_map<int,  list<pair<int, int>>::iterator> m_map;
    std::list<std::pair<int, int>> m_list;
    size_t m_cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
