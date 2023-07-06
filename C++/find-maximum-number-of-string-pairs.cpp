// Time:  O(n)
// Space: O(1)

// freq table
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int result = 0;
        vector<int> cnt(26 * 26);
        for (const auto& w : words) {
            result += cnt[(w[1] - 'a') * 26 + (w[0] - 'a')];
            ++cnt[(w[0] - 'a') * 26 + (w[1] - 'a')];
        }
        return result;
    }
};
