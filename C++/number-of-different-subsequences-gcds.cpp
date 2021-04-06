// Time:  O(n + m * (1 + 1/2 + 1/3 + ... + 1/m)) = O(n + mlogm), m is max of nums
// Space: O(n)

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        unordered_set<int> nums_set(cbegin(nums), cend(nums));
        int max_num = *max_element(cbegin(nums), cend(nums));
        int result = 0;
        for (int i = 1; i <= max_num; ++i) {
            int d = 0;
            for (int x = i; x <= max_num; x += i) {
                if (!nums_set.count(x)) {
                    continue;
                }
                d = gcd(d, x);  // total time: O(log(min(d, x)) = O(logd), where d keeps the same or gets smaller
                if (d == i) {
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};
