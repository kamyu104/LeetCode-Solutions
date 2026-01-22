// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int vowelConsonantScore(string s) {
        static const string VOWELS = "aeiou";

        int v = 0, c = 0;
        for (const auto& x : s) {
            if (VOWELS.find(x) != string::npos) {
                ++v;
            } else if (isalpha(x)) {
                ++c;
            }
        }
        return c ? v / c : 0;
    }
};
