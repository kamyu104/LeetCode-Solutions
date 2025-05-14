// Time:  O(n + 26)
// Space: O(n + 26)

// freq table, counting sort, greedy
class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        vector<int> cnt2(ranges::max(cnt) + 1);
        for (const auto& x : cnt) {
            ++cnt2[x];
        }
        int result = 0;
        for (int i = 0, total = 26 - k; i < size(cnt2); ++i) {
            const int c = min(cnt2[i], total);
            result += i * c;
            total -= c;
            if (total == 0) {
                break;
            }
        }
        return result;
    }
};
