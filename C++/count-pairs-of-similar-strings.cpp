// Time:  O(n * l)
// Space: O(n)

// freq table, bitmask
class Solution {
public:
    int similarPairs(vector<string>& words) {
        int result = 0;
        unordered_map<int, int> cnt;
        for (const auto& w : words) {
            int mask = 0;
            for (const auto& c : w) {
                mask |= 1 << (c - 'a');
            }
            result += cnt[mask]++;
        }
        return result;
    }
};
