// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        unordered_map<char, char> lookup;
        for (int i = 0; i < str1.size(); ++i) {
            lookup.emplace(str1[i], str2[i]);
            if (lookup[str1[i]] != str2[i]) {
                return false;
            }
        }
        unordered_set<char> count(str2.cbegin(), str2.cend());
        return count.size() < 26;
    }
};
