// Time:  ctor: O(k)
//        add: O(1)
//        showFirstUnique: O(1)
// Space: O(n)

class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (const auto& num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        if (q_.size()) {
            return q_.front().first;
        }
        return -1;
    }
    
    void add(int value) {
        if (!dup_.count(value) && !q_.count(value)) {
            q_[value] = true;
            return;
        }
        if (q_.count(value)) {
            q_.pop(value);
            dup_.emplace(value);
        }
    }

private:
    template<typename K, typename V>
    class OrderedDict {
    public:
        bool count(const K& key) const {
            return map_.count(key);
        }
        
        V& operator[](const K& key) {
            if (!map_.count(key)) {
                list_.emplace_front();
                list_.begin()->first = key;
                map_[key] = list_.begin();
            }
            return map_[key]->second;
        }

        void popitem() {
            auto del = list_.front(); list_.pop_front();
            map_.erase(del.first);
        }
        
        pair<K, V> front() {
            return *list_.crbegin();
        }
        
        void pop(const K& key) {
            if (!map_.count(key)) {
                return;
            }
            list_.erase(map_[key]);
            map_.erase(key);
        }
        
        vector<K> keys() const {
            vector<K> result;
            transform(list_.crbegin(), list_.crend(), back_inserter(result),
                      [](const auto& x) {
                          return x.first;
                      });
            return result;
        }
        
        int size() const {
            return list_.size();
        }
    
    private:
        list<pair<K, V>> list_;
        unordered_map<K, typename list<pair<K, V>>::iterator> map_;
    };
    
    OrderedDict<int, bool> q_;
    unordered_set<int> dup_;
};
