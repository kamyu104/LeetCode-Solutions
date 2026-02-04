// Time:  ctor:                 O(1)
//        addRider:             O(1)
//        addDriver:            O(1)
//        matchDriverWithRider: O(1)
//        cancelRider:          O(1)
// Space: O(n)

// ordered dict
class RideSharingSystem {
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders_[riderId] = true;
    }
    
    void addDriver(int driverId) {
        drivers_[driverId] = true;
    }
    
    vector<int> matchDriverWithRider() {
        if (empty(riders_) || empty(drivers_)) {
            return {-1, -1};
        }
        const auto r = riders_.front().first;
        const auto d = drivers_.front().first;
        riders_.pop(r);
        drivers_.pop(d);
        return {d, r};        
    }
    
    void cancelRider(int riderId) {
        if (riders_.count(riderId)) {
            riders_.pop(riderId);
        }
    }

private:
    template<typename K, typename V>
    class OrderedDict {
    public:
        int count(const K& key) const {
            return lookup_.count(key);
        }
        
        V& operator[](const K& key) {
            if (!lookup_.count(key)) {
                list_.emplace_back();
                list_.rbegin()->first = key;
                lookup_[key] = prev(end(list_));
            }
            return lookup_[key]->second;
        }

        pair<K, V> front() const {
            return *cbegin(list_);
        }
        
        void pop(const K& key) {
            if (!lookup_.count(key)) {
                return;
            }
            list_.erase(lookup_[key]);
            lookup_.erase(key);
        }
        
        bool empty() const {
            return list_.empty();
        }
    
    private:
        list<pair<K, V>> list_;
        unordered_map<K, typename list<pair<K, V>>::iterator> lookup_;
    };

    OrderedDict<int, bool> riders_, drivers_;
};
