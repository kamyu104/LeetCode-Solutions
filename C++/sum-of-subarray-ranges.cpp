// Time:  O(n)
// Space: O(n)

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int64_t result = 0;
        vector<int> stk;
        for (int i = 0; i <= size(nums); ++i) {
            const int x = (i < size(nums)) ? nums[i] : numeric_limits<int>::max();
            while (!empty(stk) && nums[stk.back()] <= x) {
                const int64_t j = stk.back(); stk.pop_back();
                const int64_t k = !empty(stk) ? stk.back() : -1;
                result += nums[j] * (j - k) * (i - j);
            }
            stk.emplace_back(i);
        }
        stk.clear();
        for (int i = 0; i <= size(nums); ++i) {
            const int x = (i < size(nums)) ? nums[i] : numeric_limits<int>::min();
            while (!empty(stk) && nums[stk.back()] >= x) {
                const int64_t j = stk.back(); stk.pop_back();
                const int64_t k = !empty(stk) ? stk.back() : -1;
                result -= nums[j] * (j - k) * (i - j);
            }
            stk.emplace_back(i);
        }
        return result;
    }
};
