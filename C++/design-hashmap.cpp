// Time:  O(1)
// Space: O(n)

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : data_(10000) {
        
    }
    
    /** value will always be positive. */
    void put(int key, int value) {
        auto& list = data_[key % data_.size()];
        auto it = find_if(list.begin(), list.end(),
                          [&](const pair<int, int>& i) { return i.first == key; } );
        if (it != list.end()) {
            it->second = value;
        } else {
            list.emplace_back(key, value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto& list = data_[key % data_.size()];
        auto it = find_if(list.begin(), list.end(),
                          [&](const pair<int, int>& i) { return i.first == key; } );
        if (it != list.end()) {
            return it->second;
        } else {
            return -1;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& list = data_[key % data_.size()];
        auto it = find_if(list.begin(), list.end(),
                          [&](const pair<int, int>& i) { return i.first == key; } );
        if (it != list.end()) {
            list.erase(it);
        }
    }

private:
    vector<list<pair<int, int>>> data_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
