// Time:  O(1), per operation.
// Space: O(k), k is capacity of cache.

#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : capa_(capacity) {
    }
    
    int get(int key) {
        if (map_.find(key) != map_.end()) {
            // It key exists, update it.
            const auto value = map_[key]->second;
            update(key, value);
            return value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        // If cache is full while inserting, remove the last one.
        if (map_.find(key) == map_.end() && list_.size() == capa_) {
            auto del = list_.back(); list_.pop_back();
            map_.erase(del.first);
        }
         update(key, value);
    }
    
private:
    list<pair<int, int>> list_; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> map_; // key, list iterator
    int capa_;
    
    // Update (key, iterator of (key, value)) pair
    void update(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            list_.erase(it->second);
        }
        list_.emplace_front(key, value);
        map_[key] = list_.begin();
    }
};
