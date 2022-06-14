// Time:  O(n * s)
// Space: O(m)

// brute force
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        const auto& transform = [](char c) {
            return ::isdigit(c) ? c - '0' : (::islower(c) ? c - 'a' + 10 : c - 'A' + 36);
        };
        vector<vector<bool>> lookup(62, vector<bool>(62));
        for (const auto& m : mappings) {
            lookup[transform(m[0])][transform(m[1])] = true;
        }
        const auto& check = [&](int i) {
            for (int j = 0; j < size(sub); ++j) {
                if (sub[j] != s[i + j] && (!lookup[transform(sub[j])][transform(s[i + j])])) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < size(s) - size(sub) + 1; ++i) {
            if (check(i)) {
                return true;
            }
        }
        return false;
    }
};

// Time:  O(n * s)
// Space: O(m)
// brute force
class Solution2 {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> lookup;
        for (const auto& m : mappings) {
            lookup[m[0]].emplace(m[1]);
        }
        const auto& check = [&](int i) {
            for (int j = 0; j < size(sub); ++j) {
                if (sub[j] != s[i + j] && (!lookup.count(sub[j]) || !lookup[sub[j]].count(s[i + j]))) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < size(s) - size(sub) + 1; ++i) {
            if (check(i)) {
                return true;
            }
        }
        return false;
    }
};
