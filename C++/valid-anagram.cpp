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

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};
