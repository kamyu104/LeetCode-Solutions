// Time:  O(1), per operation.
// Space: O(k), k is the capacity of cache.

class LFUCache {
public:
    LFUCache(int capacity) : capa_(capacity), size_(0) {
    }
    
    int get(int key) {
        if (!key_to_nodeit_.count(key)) {
            return -1;
        }
        
        auto new_node = *key_to_nodeit_[key];        
        auto& freq = std::get<2>(new_node);
        freq_to_nodes_[freq].erase(key_to_nodeit_[key]);
        if (freq_to_nodes_[freq].empty()) {
            freq_to_nodes_.erase(freq);
            if (min_freq_ == freq) {
                ++min_freq_;
            }
        }
        ++freq;
        freq_to_nodes_[freq].emplace_back(new_node);
        key_to_nodeit_[key] = prev(freq_to_nodes_[freq].end());

        return std::get<1>(*key_to_nodeit_[key]);
    }
    
   void put(int key, int value) {
        if (capa_ <= 0) {
            return;
        }

        if (get(key) != -1) {
            std::get<1>(*key_to_nodeit_[key]) = value;
            return;
        }
        
        if (size_ == capa_) {
            key_to_nodeit_.erase(std::get<0>(freq_to_nodes_[min_freq_].front()));
            freq_to_nodes_[min_freq_].pop_front();
            if (freq_to_nodes_[min_freq_].empty()) {
                freq_to_nodes_.erase(min_freq_);
            }
            --size_;
        }
        
        min_freq_ = 1;
        freq_to_nodes_[min_freq_].emplace_back(make_tuple(key, value, min_freq_));
        key_to_nodeit_[key] = prev(freq_to_nodes_[min_freq_].end());
        ++size_;
    }

private:
    int capa_;
    int size_;
    int min_freq_;
    unordered_map<int, list<tuple<int, int, int>>> freq_to_nodes_;            // freq to list of {key, val, freq}
    unordered_map<int, list<tuple<int, int, int>>::iterator> key_to_nodeit_;  // key to list iterator
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
