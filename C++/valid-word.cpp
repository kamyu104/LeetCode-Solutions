// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    bool isValid(string word) {
        static const string VOWELS = "aeiou";

        if (size(word) < 3) {
            return false;
        }
        bool vowel = false, consonant = false;
        for (const auto& c : word) {
            if (isalpha(c)) {
                if (VOWELS.find(tolower(c)) != string::npos) {
                    vowel = true;
                } else {
                    consonant = true;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return vowel && consonant;
    }
};
