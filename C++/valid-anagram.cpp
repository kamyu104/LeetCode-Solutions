// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (size(s) != size(t)) {
            return false;
        }

        unordered_map<char, int> count;
        for (const auto& c: s) {
            ++count[c];
        }
        for (const auto& c: t) {
            --count[c];
            if (count[c] < 0) {
                return false;
            }
        }
        return true;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (size(s) != size(t)) {
            return false;
        }

        sort(begin(s), end(s));
        sort(begin(t), end(t));
        return s == t;
    }
};
