// Time:  O(26n)
// Space: O(26)

class Solution {
public:
    int minimumDistance(string word) {
        vector<int> dp(26);
        for (int i = 0; i < word.length() - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            for (int a = 0; a < 26; ++a) {
                dp[b] = max(dp[b], dp[a] - distance(a, c) + distance(b, c));
            }
        }
        int result = 0;
        for (int i = 0; i < word.length() - 1; ++i) {
            result += distance(word[i] - 'A', word[i + 1] - 'A');
        }
        return result - *max_element(dp.cbegin(), dp.cend());
    }

private:
    int distance(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};

// Time:  O(52n)
// Space: O(52)
class Solution2 {
private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    int minimumDistance(string word) {
        unordered_map<pair<int, int>, int, PairHash<int>> dp = {{{-1, -1}, 0}};
        for (const auto& w : word) {
            int c = w - 'A';
            unordered_map<pair<int, int>, int, PairHash<int>> new_dp;
            for (const auto& [p, v] : dp) {
                const auto& [a, b] = p;
                if (!new_dp.count(make_pair(c, b)) || 
                    v + distance(a, c) < new_dp[make_pair(c, b)]) {
                    new_dp[make_pair(c, b)] = v + distance(a, c);
                }
                if (!new_dp.count(make_pair(a, c)) || 
                    v + distance(b, c) < new_dp[make_pair(a, c)]) {
                    new_dp[make_pair(a, c)] = v + distance(b, c);
                };
            }
            dp = move(new_dp);
        }
        return min_element(dp.cbegin(), dp.cend(),
                           [](const auto&a, const auto& b) {
                                return a.second < b.second;
                           })->second;
    }

private:
    int distance(int a, int b) {
        if (a == -1 || b == -1) {
            return 0;
        }
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};
