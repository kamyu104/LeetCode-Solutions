// Time:  O(nlog(logn)) on averge
// Space: O(n)

// prefix sum, number theory
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = max(prefix[i], nums[i]);
        }
        vector<int> suffix(size(nums) + 1, numeric_limits<int>::max());
        for (int i = size(nums) - 1; i >= 0 ; --i) {
            suffix[i] = min(suffix[i + 1], nums[i]);
        }
        vector<int> prefix2(size(nums));
        for (int i = 0; i + 1 < size(nums); ++i) {
            prefix2[i + 1] = prefix2[i] + (nums[i] > nums[i + 1] ? 1 : 0);
        }

        const auto& check = [&](int k) {
            if (size(nums) % k) {
                return false;
            }
            for (int i = 0; i < size(nums); i += k) {
                if (!(prefix[i] <= suffix[i] && (prefix2[i + k - 1] - prefix2[i]) + (nums[i + k - 1] > nums[i] ? 1 : 0) <= 1)) {
                    return false;
                }
            }
            return true;
        };

        int result = 0;
        for (int k = 1; k <= size(nums); ++k) {
            if (check(k)) {
                result += k;
            }
        }
        return result;
    }
};
