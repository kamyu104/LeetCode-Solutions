// Time:  ctor: O(n)
//        pickIndex: O(logn)
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
        return distance(prefix_sum_.cbegin(),
                        upper_bound(prefix_sum_.cbegin(), prefix_sum_.cend(), target));
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
