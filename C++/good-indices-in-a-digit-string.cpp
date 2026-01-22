// Time:  O(n)
// Space: O(1)

// math, sliding window
class Solution {
public:
    vector<int> goodIndices(string s) {
        vector<int> result;
        for (int i = 0, curr = 0, base = 1; i < size(s); ++i) {
            if (i == base * 10) {
                base *= 10;
            }
            curr = (curr % base) * 10 + (s[i] - '0');
            if (curr == i) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
