// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    string trimTrailingVowels(string s) {
        static const string VOWELS = "aeiou";

        while (!empty(s) && VOWELS.find(s.back()) != string::npos) {
            s.pop_back();
        }
        return s;
    }
};

// Time:  O(n)
// Space: O(1)
// string
class Solution2 {
public:
    string trimTrailingVowels(string s) {
        static const string VOWELS = "aeiou";

        return s.substr(0, s.find_last_not_of(VOWELS) + 1);
    }
};
