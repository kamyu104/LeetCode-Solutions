// Time:  ctor:    O(n)
//        lock:    O(1)
//        unlock:  O(1)
//        upgrade: O(n)
// Space: O(n)

class LockingTree {
public:
    LockingTree(vector<int>& parent)
      : parent_(parent)
      , children_(size(parent)) {
        for (int i = 0; i < size(parent); ++i) {
            if (parent[i] != -1) {
                children_[parent_[i]].emplace_back(i);
            }
        }
    }
    
    bool lock(int num, int user) {
        if (locked_.count(num)) {
            return false;
        }
        locked_[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (!locked_.count(num) || locked_[num] != user) {
            return false;
        }
        locked_.erase(num);
        return true;
    }
    
    bool upgrade(int num, int user) {
        for (int node = num; node != -1; node = parent_[node]) {
            if (locked_.count(node)) {
                return false;
            }
        }
        bool result = false;
        vector<int> stk = {num};
        while (!empty(stk)) {
            auto node = stk.back(); stk.pop_back();
            for (const auto& child : children_[node]) {
                if (locked_.count(child)) {
                    locked_.erase(child);
                    result = true;
                }
                stk.emplace_back(child);
            }
        }
        if (result) {
            locked_[num] = user;
        }
        return result;
    }

private:
    const vector<int>& parent_;
    vector<vector<int>> children_;
    unordered_map<int, int> locked_;
};
