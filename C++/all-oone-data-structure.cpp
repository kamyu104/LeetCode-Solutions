// Time:  O(1), per operation
// Space: O(k)

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!bucketOfKey_.count(key)) {
            bucketOfKey_[key] = buckets_.insert(buckets_.begin(), {0, {key}});
        }
            
        auto next = bucketOfKey_[key], bucket = next++;
        if (next == buckets_.end() || next->value > bucket->value + 1) {
            next = buckets_.insert(next, {bucket->value + 1, {}});
        }
        next->keys.insert(key);
        bucketOfKey_[key] = next;
        
        bucket->keys.erase(key);
        if (bucket->keys.empty()) {
            buckets_.erase(bucket);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!bucketOfKey_.count(key)) {
            return;
        }

        auto prev = bucketOfKey_[key], bucket = prev--;
        bucketOfKey_.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets_.begin() || prev->value < bucket->value - 1) {
                prev = buckets_.insert(bucket, {bucket->value - 1, {}});
            }
            prev->keys.insert(key);
            bucketOfKey_[key] = prev;
        }
        
        bucket->keys.erase(key);
        if (bucket->keys.empty()) {
            buckets_.erase(bucket);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets_.empty() ? "" : *(buckets_.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets_.empty() ? "" : *(buckets_.begin()->keys.begin());
    }

private:
    struct Bucket {
        int value;
        unordered_set<string> keys;
    };
    list<Bucket> buckets_;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
 
