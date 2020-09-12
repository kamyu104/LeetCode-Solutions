// Time:  O(1)
// Space: O(n)

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() : gen_(random_device()()) {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (used_.count(val)) {
            return false;
        }

        set_.emplace_back(val);
        used_[val] = set_.size() - 1;

        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!used_.count(val)) {
            return false;
        }

        used_[set_.back()] = used_[val];
        swap(set_[used_[val]], set_.back());

        used_.erase(val);
        set_.pop_back();

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> dist(0, set_.size() - 1);
        return set_[dist(gen_)];
    }

private:
    vector<int> set_;
    unordered_map<int, int> used_;
    default_random_engine gen_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
 
