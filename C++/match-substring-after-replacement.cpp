// Time:  O(n * k), n = len(s), k = len(sub)
// Space: O(m), m = len(mappings)

// brute force
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        const auto& f = [](char c) {
            return ::isdigit(c) ? c - '0' : (::islower(c) ? c - 'a' + 10 : c - 'A' + 36);
        };
        vector<vector<bool>> lookup(62, vector<bool>(62));
        for (const auto& m : mappings) {
            lookup[f(m[0])][f(m[1])] = true;
        }
        transform(begin(s), end(s), begin(s), f);
        transform(begin(sub), end(sub), begin(sub), f);
        const auto& check = [&](int i) {
            for (int j = 0; j < size(sub); ++j) {
                if (sub[j] != s[i + j] && (!lookup[sub[j]][s[i + j]])) {
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

// Time:  O(n * k), n = len(s), k = len(sub)
// Space: O(m), m = len(mappings)
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
