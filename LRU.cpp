#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        // Move the accessed key to the front of the list
        auto it = cache[key];
        int value = it->second;
        lru.erase(it);
        lru.push_front({key, value});
        cache[key] = lru.begin();
        return value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            // Remove the least recently used key
            if (lru.size() == capacity) {
                int k = lru.back().first;
                cache.erase(k);
                lru.pop_back();
            }
            // Insert the new key-value pair
            lru.push_front({key, value});
            cache[key] = lru.begin();
        } else {
            // Update the value of the key
            auto it = cache[key];
            it->second = value;
            lru.erase(it);
            lru.push_front({key, value});
            cache[key] = lru.begin();
        }
    }
    
private:
    int capacity;
    std::list<std::pair<int, int>> lru;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
};
