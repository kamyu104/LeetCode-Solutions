// Time:  O(n + 26)
// Space: O(26)

// prefix sum
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        vector<int64_t> prefix1(size(nextCost) + 1);
        for (int i = 0; i < size(nextCost); ++i) {
            prefix1[i + 1] = prefix1[i] + nextCost[i];
        }
        vector<int64_t> prefix2(size(previousCost) + 1);
        for (int i = 0; i < size(previousCost); ++i) {
            prefix2[i + 1] = prefix2[i] + previousCost[i];
        }
        int64_t result = 0;
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == t[i]) {
                continue;
            }
            const int left = s[i] - 'a';
            const int right = t[i] - 'a';
            if (left <= right) {
                result += min(prefix1[right] - prefix1[left], prefix2.back() - (prefix2[right + 1] - prefix2[left + 1]));
            } else {
                result += min(prefix2[left + 1] - prefix2[right + 1], prefix1.back() - (prefix1[left] - prefix1[right]));
            }
        }
        return result;
    }
};
