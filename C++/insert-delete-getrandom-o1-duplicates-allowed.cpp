// Time:  O(1)
// Space: O(n)

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool has = used_.count(val);

        list_.emplace_back(val);
        used_[val].emplace_back(list_.size() - 1);

        return !has; 
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!used_.count(val)) {
            return false;
        }

        used_[list_.back()].back() = used_[val].back();
        swap(list_[used_[val].back()], list_.back());

        used_[val].pop_back();
        if (used_[val].empty()) {
            used_.erase(val);
        }
        list_.pop_back();

        return true;  
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return list_[rand() % list_.size()];
    }

private:
    vector<int> list_;
    unordered_map<int, vector<int>> used_;
};


// Time:  O(1)
// Space: O(n)
class RandomizedCollection2 {
public:
    /** Initialize your data structure here. */
    RandomizedCollection2() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool has = used_.count(val);

        list_.emplace_back(val);
        used_.emplace(val, list_.size() - 1);

        return !has; 
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!used_.count(val)) {
            return false;
        }

        auto it_to_delete = used_.find(val);
        auto it_to_back = used_.find(list_.back());
        it_to_back->second = it_to_delete->second;
        swap(list_[it_to_delete->second], list_.back());

        used_.erase(it_to_delete);
        list_.pop_back();

        return true;  
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return list_[rand() % list_.size()];
    }

private:
    vector<int> list_;
    unordered_multimap<int, int> used_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
 
