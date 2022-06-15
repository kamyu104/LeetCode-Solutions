// Time:  O(26 * n * l)
// Space: O(n * l)

// hash table, math
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> lookup(26);
        for (const auto& idea : ideas) {
            lookup[idea[0] - 'a'].emplace(idea.substr(1));
        }
        vector<vector<int64_t>> cnt(26, vector<int64_t>(26));
        for (int i = 0; i < 26; ++i) {
            for (const auto& x : lookup[i]) {
                for (int j = 0; j < 26; ++j) {
                    if (j == i) {
                        continue;
                    }
                    cnt[i][j] += !lookup[j].count(x);
                }
            }
        }
        int64_t result = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                result += cnt[i][j] * cnt[j][i];
            }
        }
        return result * 2;
    }
};

// Time:  O(26^2 * n * l)
// Space: O(n * l)
// hash table, math
class Solution2 {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> lookup(26);
        for (const auto& idea : ideas) {
            lookup[idea[0] - 'a'].emplace(idea.substr(1));
        }
        int64_t result = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                int common = 0;
                for (const auto& x : lookup[i]) {
                    common += lookup[j].count(x);
                }
                result += (size(lookup[i]) - common) * (size(lookup[j]) - common);
            }
        }
        return result * 2;
    }
};
