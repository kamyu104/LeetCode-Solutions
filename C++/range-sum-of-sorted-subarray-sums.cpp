// Time:  O(nlog(sum(nums)))
// Space: O(n)

// binary search + sliding window solution
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        static const int MOD = 1e9 + 7;
        vector<uint64_t> prefix(cbegin(nums), cend(nums));
        for (uint64_t i = 0; i + 1 < nums.size(); ++i) {
            prefix[i + 1] += prefix[i];
        }
        const uint64_t min = *min_element(cbegin(nums), cend(nums));
        const uint64_t& max = accumulate(cbegin(nums), cend(nums), 0ull);
        return (sumLessOrEqualTo(prefix, nums, min, max, right) -
                sumLessOrEqualTo(prefix, nums, min, max, left - 1)) % MOD;
    }
    
private:
    uint64_t sumLessOrEqualTo(const vector<uint64_t>& prefix,
                              const vector<int>& nums,
                              uint64_t left, uint64_t right,
                              uint64_t target) {
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (countUntil(nums, mid) >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return sumUntil(nums, prefix, left) - left * (countUntil(nums, left) - target);
    }
    
    uint64_t countUntil(const vector<int>& nums,
                        uint64_t target) {
        uint64_t result = 0, curr = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            curr += nums[right];
            for (; curr > target; ++left) {
                curr -= nums[left];
            }
            result += right - left + 1;
        }
        return result;
    }
    
    uint64_t sumUntil(const vector<int>& nums,
                      const vector<uint64_t>& prefix,
                      uint64_t target) {
        uint64_t result = 0, curr = 0, total = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            curr += nums[right];
            total += nums[right] * (right - left + 1);
            for (; curr > target; ++left) {
                curr -= nums[left];
                total -= prefix[right] - (left - 1 >= 0 ? prefix[left - 1] : 0);
            }
            result += total;
        }
        return result;
    }
};

// Time:  O(rlogr), worst: O(n^2 * logn)
// Space: O(n)
// heap solution
class Solution2 {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        static const int MOD = 1e9 + 7;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (int i = 0; i < n; ++i) {
            min_heap.emplace(nums[i], i + 1);
        }
        int result = 0;
        for (int i = 1; i <= right; ++i) {
            auto [total, j] = min_heap.top(); min_heap.pop();
            if (i >= left) {
                result = (result + total) % MOD;
            }
            if (j + 1 <= n) {
                min_heap.emplace(total + nums[j], j + 1);
            }
        }
        return result;
    }
};
