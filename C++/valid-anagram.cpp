// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> count;

        for (const auto& c: s) {
            ++count[tolower(c)];
        }

        for (const auto& c: t) {
            --count[tolower(c)];
            if (count[tolower(c)] < 0) {
                return false;
            }
        }

        return true;
    }
};
