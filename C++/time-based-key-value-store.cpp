// Time:  set: O(1)
//        get: O(logn)
// Space: O(n)

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        lookup_[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (!lookup_.count(key)) {
            return "";
        }
        auto it = upper_bound(lookup_[key].cbegin(),
                              lookup_[key].cend(),
                              make_pair(timestamp + 1, ""),
                              [](const pair<int, string>& lhs,
                                 const pair<int, string>& rhs) {
                                  return lhs.first < rhs.first;
                              });
        return it != lookup_[key].cbegin() ? prev(it)->second : "";
    }
    
private:
    unordered_map<string, vector<pair<int, string>>> lookup_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
 
