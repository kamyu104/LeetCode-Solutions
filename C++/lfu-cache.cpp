// Time:  O(1), per operation
// Space: O(k), k is the capacity of cache

class LFUCache {
public:
    LFUCache(int capacity) : capa_(capacity), size_(0), min_freq_(numeric_limits<int>::max()) {
    }
    
    int get(int key) {
        if (!key_to_nodeit_.count(key)) {
            return -1;
        }
        const auto value = std::get<VAL>(*key_to_nodeit_[key]);
        update(key, value);
        return value;
    }
    
   void put(int key, int value) {
        if (capa_ <= 0) {
            return;
        }

        if (!key_to_nodeit_.count(key) && size_ == capa_) {
            key_to_nodeit_.erase(std::get<KEY>(freq_to_nodes_[min_freq_].front()));
            freq_to_nodes_[min_freq_].pop_front();
            if (freq_to_nodes_[min_freq_].empty()) {
                freq_to_nodes_.erase(min_freq_);
            }
            --size_;
        }
        update(key, value);
    }

private:
    enum Data {KEY, VAL, FREQ}; 
    int capa_;
    int size_;
    int min_freq_;
    unordered_map<int, list<tuple<int, int, int>>> freq_to_nodes_;            // freq to list of {key, val, freq}
    unordered_map<int, list<tuple<int, int, int>>::iterator> key_to_nodeit_;  // key to list iterator

    void update(int key, int value) {
        int freq = 0;
        if (key_to_nodeit_.count(key)) {
            auto old_node = *key_to_nodeit_[key];        
            freq = std::get<FREQ>(old_node);
            freq_to_nodes_[freq].erase(key_to_nodeit_[key]);
            if (freq_to_nodes_[freq].empty()) {
                freq_to_nodes_.erase(freq);
                if (min_freq_ == freq) {
                    ++min_freq_;
                }
            }
            --size_;
        }
        min_freq_ = min(min_freq_, ++freq);
        freq_to_nodes_[freq].emplace_back(key, value, freq);
        key_to_nodeit_[key] = prev(freq_to_nodes_[freq].end());
        ++size_;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
