// Time:  ctor:   O(1)
//        change: O(logn)
//        find:   O(1)
// Space: O(n)

// bst
class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (idx_to_num_.count(index)) {
            num_to_idxs_[idx_to_num_[index]].erase(index);
            if (empty(num_to_idxs_[idx_to_num_[index]])) {
                num_to_idxs_.erase(idx_to_num_[index]);
            }
        }
        idx_to_num_[index] = number;
        num_to_idxs_[number].emplace(index);
    }
    
    int find(int number) {
        if (num_to_idxs_.count(number)) {
            return *cbegin(num_to_idxs_[number]);
        }
        return -1;
    }

private:
    unordered_map<int, int> idx_to_num_;
    unordered_map<int, set<int>> num_to_idxs_;
};
