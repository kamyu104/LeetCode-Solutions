// Time:  O(n)
// Space: O(1)

// Sliding window solution.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = -1, sum = 0, min_size = numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_size = min(min_size, i - start);
                sum -= nums[++start];
            }
        }
        if (min_size == numeric_limits<int>::max()) {
            return 0;
        }
        return min_size;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// Binary search solution.
class Solution2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_size = numeric_limits<int>::max();
        vector<int> sum_from_start(nums.size() + 1);
        partial_sum(nums.cbegin(), nums.cend(), sum_from_start.begin() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            const auto& end_it = lower_bound(sum_from_start.cbegin() + i,
                                             sum_from_start.cend(),
                                             sum_from_start[i] + s);
            if (end_it != sum_from_start.cend()) {
                int end = static_cast<int>(end_it - sum_from_start.cbegin());
                min_size = min(min_size, end - i);
            }
        }
        if (min_size == numeric_limits<int>::max()) {
            return 0;
        }
        return min_size;
    }
};
