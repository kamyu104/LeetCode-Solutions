// Time:  O(logn)
// Space: O(n)

class Solution {
public:
    Solution(vector<int> w) :
        prefix_sum_(w.size()),
        uni_((random_device())()) {

        partial_sum(w.cbegin(), w.cend(), prefix_sum_.begin(), plus<int>());
        uni_ = uniform_int_distribution<int>{0, prefix_sum_.back() - 1};
    }
    
    int pickIndex() {
        const auto target = uni_(gen_);
        int left = 0, right = prefix_sum_.size() - 1;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (prefix_sum_[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    vector<int> prefix_sum_;
    default_random_engine gen_;
    uniform_int_distribution<int> uni_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
 
