// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if (6 * size(nums1) < 1 * size(nums2) || 6 * size(nums2) < 1 * size(nums1)) {
            return -1;
        }
        vector<int> count(6);
        int diff = accumulate(cbegin(nums2), cend(nums2), 0) - accumulate(cbegin(nums1), cend(nums1), 0);
        if (diff < 0) {
            swap(nums1, nums2);
            diff = -diff;
        }
        for (const auto& num : nums1) {
            ++count[6 - num];
        }
        for (const auto& num : nums2) {
            ++count[num - 1];
        }
        int result = 0;
        for (int i = 5; i >= 1; --i) {
            if (!count[i]) {
                continue;
            }
            int cnt = min(count[i], (diff + i - 1) / i);
            result += cnt;
            diff -= i * cnt;
            if (diff <= 0) {
                break;
            }
        }
        return result;
    }
};
