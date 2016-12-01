// Time:  O(1), per operation.
// Space: O(k), k is the capacity of cache.

#include <list>

class LFUCache{
public:
    // @param capacity, an integer
    LFUCache(int capacity) : capa_(capacity) {
    }

    int get(int key) {
        if (map_.find(key) != map_.end() && capa_) {
            // It key exists, update it.
            const auto value = map_[key]->value;
            update(key, value);
            return value;
        } else {
            return -1;
        }
    }

    void set(int key, int value) 
        if (!capa_) {
            return;
        }
        // If cache is full while inserting, remove the last one.
        if (map_.find(key) == map_.end() && list_.size() == capa_) {
            auto del = list_.front(); list_.pop_front();
            map_.erase(del.key);
        }
        update(key, value);
    }

private:
    struct node {
        node(int k, int v, int f) : key(k), value(v), freq(f) {}
        int key;
        int value;
        int freq;
    };
    using List = list<node>;
    List list_; // key, value
    unordered_map<int, List::iterator> map_; // key, list iterator
    int capa_;

    // Update (key, iterator of (key, value)) pair
    void update(int key, int value) {
        int freq = 0;
        auto l_it = list_.begin();
        auto it = map_.find(key);
        if (it != map_.end()) {
            freq = it->second->freq;
            l_it = next(it->second);
            list_.erase(it->second);
        }
        ++freq;
        while (l_it != list_.end() && freq >= l_it->freq) {
            ++l_it;
        }
        map_[key] = list_.emplace(l_it, node(key, value, freq));
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */
