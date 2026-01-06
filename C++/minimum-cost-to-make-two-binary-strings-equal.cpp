// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        vector<int> cnt(2);
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == t[i]) {
                continue;
            }
            ++cnt[s[i] - '0'];
        }
        const int64_t mn = min(cnt[0], cnt[1]), mx = max(cnt[0], cnt[1]);
        const int64_t q = (mx - mn) / 2, r = (mx - mn) % 2;
        return mn * min(swapCost, 2 * flipCost) + q * min(crossCost + swapCost, 2 * flipCost) + r * flipCost;
    }
};

// Time:  O(n)
// Space: O(1)
// math
class Solution2 {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        vector<int> cnt(2);
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == t[i]) {
                continue;
            }
            ++cnt[s[i] - '0'];
        }
        const int64_t mn = min(cnt[0], cnt[1]), mx = max(cnt[0], cnt[1]);
        const int64_t q = (mx - mn) / 2, r = (mx - mn) % 2;
        return min({(mx + mn) * flipCost,
                     mn * swapCost + (mx - mn) * flipCost,
                     mn * swapCost + q * (crossCost + swapCost) + r * flipCost});
    }
};
