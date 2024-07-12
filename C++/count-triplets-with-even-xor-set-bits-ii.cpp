// Time:  O(nlogr), r = max(max(a), max(b), max(c))
// Space: O(1)

// bit manipulation, parity
class Solution {
public:
    long long tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        const auto& count = [](const auto& a) {
            const auto& odd = accumulate(cbegin(a), cend(a), 0, [](const auto& total, const auto& x) {
                return total + (__builtin_popcount(x) & 1);
            });
            return vector<int64_t>{static_cast<int>(size(a)) - odd, odd};
        };

        vector<vector<int64_t>> cnt = {count(a), count(b), count(c)};
        int64_t result = 0;
        for (int i = 0; i < 4; ++i) {
            result += cnt[0][i == 0 || i == 1 ? 0 : 1] * 
                      cnt[1][i == 0 || i == 2 ? 0 : 1] *
                      cnt[2][i == 0 || i == 3 ? 0 : 1];
        }
        return result;
    }
};

// Time:  O(nlogr), r = max(max(a), max(b), max(c))
// Space: O(1)
// bit manipulation, parity
class Solution2 {
public:
    long long tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        const auto& count = [](const auto& a) {
            const auto& odd = accumulate(cbegin(a), cend(a), 0, [](const auto& total, const auto& x) {
                return total + (__builtin_popcount(x) & 1);
            });
            return pair<int64_t, int64_t>(static_cast<int>(size(a)) - odd, odd);
        };

        const auto& [even1, odd1] = count(a);
        const auto& [even2, odd2] = count(b);
        const auto& [even3, odd3] = count(c);
        return even1 * even2 * even3 + even1 * odd2 * odd3 + odd1 * even2 * odd3 + odd1 * odd2 * even3;
    }
};
