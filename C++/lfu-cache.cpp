// Time:  O(1), per operation.
// Space: O(k), k is the capacity of cache.

class LFUCache {
public:
    LFUCache(int capacity) : capa_(capacity), size_(0) {
    }
    
    int get(int key) {
        if (!key_to_val_freq_.count(key)) {
            return -1;
        }
        
        freq_to_keys_[key_to_val_freq_[key].second].erase(key_to_it_[key]);
        if (freq_to_keys_[key_to_val_freq_[key].second].empty()) {
            freq_to_keys_.erase(key_to_val_freq_[key].second);
            if (min_freq_ == key_to_val_freq_[key].second) {
                ++min_freq_;
            }
        }
        
        ++key_to_val_freq_[key].second;
        freq_to_keys_[key_to_val_freq_[key].second].emplace_back(key);
        key_to_it_[key] = prev(freq_to_keys_[key_to_val_freq_[key].second].end());

        return key_to_val_freq_[key].first;
    }
    
   void put(int key, int value) {
        if (capa_ <= 0) {
            return;
        }

        if (get(key) != -1) {
            key_to_val_freq_[key].first = value;
            return;
        }
        
        if (size_ == capa_) {
            key_to_val_freq_.erase(freq_to_keys_[min_freq_].front());
            key_to_it_.erase(freq_to_keys_[min_freq_].front());
            freq_to_keys_[min_freq_].pop_front();
            --size_;
        }
        
        min_freq_ = 1;
        key_to_val_freq_[key] = {value, min_freq_};
        freq_to_keys_[min_freq_].emplace_back(key);
        key_to_it_[key] = prev(freq_to_keys_[min_freq_].end());
        ++size_;
    }

private:
    int capa_;
    int size_;
    int min_freq_;
    unordered_map<int, list<int>> freq_to_keys_;         // freq to list of keys
    unordered_map<int, list<int>::iterator> key_to_it_;  // key to list iterator
    unordered_map<int, pair<int, int>> key_to_val_freq_; // key to {value, freq}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
