// Time:  O(n * l)
// Space: O(1)

// freq table
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        vector<int> prev;
        for (const auto& x : words) {
            vector<int> cnt(26);
            for (const auto& c : x) {
                ++cnt[c - 'a'];
            }
            if (!empty(prev) && prev == cnt) {
                continue;
            }
            prev = move(cnt);
            result.emplace_back(x);
        }
        return result;
    }
};

// Time:  O(n * llogl)
// Space: O(l)
// sort
class Solution2 {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prev;
        for (const auto& x : words) {
            string s(x);
            sort(begin(s), end(s));
            if (!empty(prev) && prev == s) {
                continue;
            }
            prev = move(s);
            result.emplace_back(x);
        }
        return result;
    }
};
