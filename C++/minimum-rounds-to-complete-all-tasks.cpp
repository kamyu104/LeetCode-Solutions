// Time:  O(n)
// Space: O(n)

// math, freq table
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (const auto& x : tasks) {
            ++cnt[x];
        }
        int result = 0;
        for (const auto& [_, v] : cnt) {
            if (v == 1) {
                return -1;
            }
            result += (v + 2) / 3;
        }
        return result;
    }
};
