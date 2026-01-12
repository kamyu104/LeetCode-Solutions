// Time:  O(n * m)
// Space: O(n * m)

// freq table
class Solution {
public:
    long long countPairs(vector<string>& words) {
        const auto& f = [](auto s) {
            for (int i = size(s) - 1; i >= 0; --i) {
                s[i] = 'a' + ((s[i] - s[0]) % 26 + 26) % 26;
            }
            return s;
        };

        int64_t result = 0;
        unordered_map<string, int> cnt;
        for (const auto& w : words) {
            result += cnt[f(w)]++;
        }
        return result;
    }
};
