// Time:  O(n)
// Space: O(1)

// freq table
class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnt(10);
        for (const auto& x : num) {
            ++cnt[x - '0'];
        }
        for (int i = 0; i < size(num); ++i) {
            if (cnt[i] != num[i] - '0') {
                return false;
            }
        }
        return true;
    }
};
