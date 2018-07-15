// Time:  O(1)
// Space: O(n)

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : data_(10000) {
        
    }
    
    void add(int key) {
        auto& list = data_[key % data_.size()];
        auto it = find(list.begin(), list.end(), key);
        if (it == list.end()) {
            list.emplace_back(key);
        }
    }
    
    void remove(int key) {
        auto& list = data_[key % data_.size()];
        auto it = find(list.begin(), list.end(), key);
        if (it != list.end()) {
            list.erase(it);
        }
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        auto& list = data_[key % data_.size()];
        auto it = find(list.begin(), list.end(), key);
        return it != list.end();
    }

private:
    vector<list<int>> data_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
 
