// Time:  ctor:  O(1)
//        flip:  O(1)
//        reset: O(min(f, r * c))
// Space: O(min(f, r * c))

class Solution {
public:
    Solution(int n_rows, int n_cols) :
        n_rows_(n_rows),
        n_cols_(n_cols),
        n_(n_rows * n_cols),
        gen_{(random_device())()} {
        
    }
    
    vector<int> flip() {
        uniform_int_distribution<int> uni(0, --n_);
        const auto target = uni(gen_);
        int x = get(target, target);
        lookup_[target] = get(n_, n_);
        return {x / n_cols_, x % n_cols_};
    }
    
    void reset() {
        lookup_.clear();
        n_ = n_rows_ * n_cols_;
    }

private:
    int get(int key, int default_value) {
        return lookup_.count(key) ? lookup_[key] : default_value;
    }

    int n_rows_;
    int n_cols_;
    int n_;
    unordered_map<int, int> lookup_;
    default_random_engine gen_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
 
