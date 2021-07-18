// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> lookup(cbegin(brokenLetters), cend(brokenLetters));
        int result = 0;
        bool broken = false;
        for (const auto& c : text) {
            if (c == ' ') {
              result += int(broken == false);
              broken = false;
            } else if (lookup.count(c)) {
                broken = true;
            }
        }
        return result + int(broken == false);
    }
};
