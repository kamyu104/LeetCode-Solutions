// Time:  ctor:     O(1)
//        generate: O(1), amortized
//        renew:    O(1), amortized
//        count:    O(1), amortized
// Space: O(n)

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive)
     : time_(timeToLive) {
        
    }
    
    void generate(string tokenId, int currentTime) {
        evict(currentTime);
        lookup_[tokenId] = time_ + currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        evict(currentTime);
        if (!lookup_.count(tokenId)) {
            return;
        }
        lookup_.remove(tokenId);
        lookup_[tokenId] = time_ + currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        evict(currentTime);
        return size(lookup_);
    }

private:
    void evict(int currentTime) {
        while (!empty(lookup_) && lookup_.front().second <= currentTime) {
            lookup_.remove(lookup_.front().first);
        }
    }

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
        
        void remove(const K& key) {
            list_.erase(map_[key]);
            map_.erase(key);
        }
        
        pair<K, V> front() const {
            return *list_.crbegin();
        }
        
        int size() const {
            return std::size(list_);
        }
        
        int empty() const {
            return std::empty(list_);
        }
    
    private:
        list<pair<K, V>> list_;
        unordered_map<K, typename list<pair<K, V>>::iterator> map_;
    };
    
    int time_;
    OrderedDict<string, int> lookup_;
};
