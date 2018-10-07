// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0;
        int max_sum = numeric_limits<int>::min(), cur_max = 0;
        int min_sum = numeric_limits<int>::max(), cur_min = 0;
        for (const auto& a : A) {
            cur_max = max(cur_max + a, a);
            max_sum = max(max_sum, cur_max);
            cur_min = min(cur_min + a, a);
            min_sum = min(min_sum, cur_min);
            total += a;
        }
        return max_sum > 0 ? max(max_sum, total - min_sum) : max_sum;
    }
};
