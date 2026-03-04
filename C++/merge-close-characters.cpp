// Time:  O(n + 26)
// Space: O(26)

// simulation, hash table
class Solution {
public:
    string mergeCharacters(string s, int k) {
        string result;
        vector<int> lookup(26, -1);
        for (const auto& x : s) {
            if (lookup[x - 'a'] != -1 && size(result) - lookup[x - 'a'] <= k) {
                continue;
            }
            lookup[x - 'a'] = size(result);
            result.push_back(x);
        }
        return result;
    }
};

// Time:  O(n + 26)
// Space: O(26)
// simulation, freq table, two pointers
class Solution2 {
public:
    string mergeCharacters(string s, int k) {
        string result;
        vector<int> cnt(26);
        for (const auto& x : s) {
            if (cnt[x - 'a']) {
                continue;
            }
            ++cnt[x - 'a'];
            result.push_back(x);
            if (size(result) >= k + 1) {
                --cnt[result[size(result) - (k + 1)] - 'a'];
            }
        }
        return result;
    }
};
