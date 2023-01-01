// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minimumPartition(string s, int k) {
        int result = 1;
        int64_t curr = 0;
        for (const auto& c : s) {
            if (c - '0' > k) {
                return -1;
            }
            if (curr * 10 + (c - '0') > k) {
                ++result;
                curr = 0;
            }
            curr = curr * 10 + (c - '0');
        }
        return result;
    }
};
