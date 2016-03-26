// Time:  O(1), per operation.
// Space: O(k), k is the capacity of cache.

#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : capa_(capacity) {
    }
    
    int get(int key) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            // It key exists, update it.
            auto l_it = it->second;
            int value = l_it->second;
            update(it, value);
            return value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        auto it = map_.find(key);
        // It key exists, update it.
        if (it != map_.end()) {
            update(it, value);
        } else {
            // If cache is full, remove the last one.
            if (list_.size() == capa_) {
                auto del = list_.back(); list_.pop_back();
                map_.erase(del.first);
            }
            list_.emplace_front(key, value);
            map_[key]=list_.begin();
        }
    }
    
private:
    list<pair<int, int>> list_; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> map_; // key, list iterator
    int capa_;
    
    // Update (key, iterator of (key, value)) pair
    void update(unordered_map<int, list<pair<int, int>>::iterator>::iterator it, int value) {
        auto l_it = it->second;
        int key = l_it->first;
        list_.erase(l_it);
        list_.emplace_front(key, value);
        it->second = list_.begin();
    }
};
