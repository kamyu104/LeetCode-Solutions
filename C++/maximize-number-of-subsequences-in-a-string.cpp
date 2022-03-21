// Time:  O(n)
// Space: O(1)

// counting, greedy
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int64_t result = 0;
        int cnt1 = 0, cnt2 = 0;
        for (const auto& c : text) {
            if (c == pattern[1]) {
                result += cnt1;
                ++cnt2;
            }
            if (c == pattern[0]) {
                ++cnt1;
            }
        }
        return result + max(cnt1, cnt2);  // add pattern[1] at back or pattern[0] at front
    }
};
