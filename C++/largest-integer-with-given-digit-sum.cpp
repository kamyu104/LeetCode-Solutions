// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int largestInteger(int n, int s) {
        int result = 0;
        for (int _ = 0; _ < n; ++_) {
            const auto& x = min(s, 9);
            result = result * 10 + x;
            s -= x;
        }
        return !s ? result : -1;
    }
};
