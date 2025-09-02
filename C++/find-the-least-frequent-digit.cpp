// Time:  O(logn + 10)
// Space: O(10)

// freq table
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> cnt(10);
        for (; n; n /= 10) {
            ++cnt[n % 10];
        }
        int mn = numeric_limits<int>::max();
        for (const auto& x : cnt) {
            if (x) {
                mn = min(mn, x);
            }
        }
        int i = 0;
        for (; i < size(cnt); ++i) {
            if (cnt[i] == mn) {
                break;
            }
        }
        return i;
    }
};
