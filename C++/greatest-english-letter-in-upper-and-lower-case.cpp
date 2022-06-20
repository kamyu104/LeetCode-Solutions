// Time:  O(n)
// Space: O(1)

// string, freq table
class Solution {
public:
    string greatestLetter(string s) {
        vector<int> cnt(52);
        for (const auto& c : s) {
            ++cnt[c - 'A' < 26 ? c - 'A' : c - 'a' + 26];
        }
        for (int i = 25; i >= 0; --i) {
            if (cnt[i] && cnt[i + 26]) {
                return string(1, i + 'A');
            }
        }
        return "";
    }
};

// Time:  O(n)
// Space: O(1)
// string, hash table
class Solution2 {
public:
    string greatestLetter(string s) {
        unordered_set<char> lookup(cbegin(s), cend(s));
        string result;
        for (const auto& c : lookup) {
            if (::isupper(c) && lookup.count(tolower(c))) {
                if (empty(result) || string(1, c) > result) {
                    result = string(1, c);
                }
            }
        }
        return result;
    }
};
