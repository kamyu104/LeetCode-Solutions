// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    bool doesAliceWin(string s) {
        static const string VOWELS = "aeiou";
        return any_of(cbegin(s), cend(s), [](const auto& x) {
            return VOWELS.find(x) != string::npos;
        });
    }
};
