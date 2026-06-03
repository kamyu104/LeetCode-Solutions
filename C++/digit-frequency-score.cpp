// Time:  O(logn)
// Space: O(1)

// freq table
class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> cnt(10);
        for (; n; n /= 10) {
            ++cnt[n % 10];
        }
        int result = 0;
        for (int i = 0; i < size(cnt); ++i) {
            result += i * cnt[i];
        }
        return result;
    }
};
