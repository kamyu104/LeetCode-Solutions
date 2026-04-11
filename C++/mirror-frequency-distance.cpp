// Time:  O(n + 36)
// Space: O(36)

// freq table
class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> cnt1(10), cnt2(26);
        for (const auto& x : s) {
            if (isdigit(x)) {
                ++cnt1[x - '0'];
            } else {
                ++cnt2[x - 'a'];
            }
        }
        int result = 0;
        for (int i = 0; 2 * i < size(cnt1); ++i) {
            result += abs(cnt1[i] - cnt1[size(cnt1) - 1 - i]);
        }
        for (int i = 0; 2 * i < size(cnt2); ++i) {
            result += abs(cnt2[i] - cnt2[size(cnt2) - 1 - i]);
        }
        return result;
    }
};
