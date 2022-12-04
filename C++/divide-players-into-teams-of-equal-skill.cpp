// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        const int64_t target = accumulate(cbegin(skill), cend(skill), 0ll) / (size(skill) / 2);
        unordered_map<int, int> cnt;
        for (const auto& s : skill) {
            ++cnt[s];
        }
        int64_t result = 0;
        for (const auto& [k, v] : cnt) {
            if (!cnt.count(target - k) || cnt[target - k] != cnt[k]) {
                return -1;
            }
            result += k * (target - k) * v;
        }
        return result / 2;
    }
};
