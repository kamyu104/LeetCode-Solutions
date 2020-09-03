// Time:  ctor: O(n)
//        dot_product: O(min(n, m))
// Space: O(n)

class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                lookup_[i] = nums[i];
            }
        }
    }
    
    int dotProduct(SparseVector& vec) {
        auto a = this, b = &vec;
        if (a->lookup_.size() > b->lookup_.size()) {
            swap(a, b);
        }
        int result = 0;
        for (const auto& [i, v] : a->lookup_) {
            if (b->lookup_.count(i)) {
                result += v * b->lookup_[i];
            }
        }
        return result;
    }

private:
    unordered_map<int, int> lookup_;
};
