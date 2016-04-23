// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.length() - 1; i < j;) {
            if (is_vowel(tolower(s[i])) && 
                is_vowel(tolower(s[j]))) {
                swap(s[i++], s[j--]);
            } else if (!is_vowel(tolower(s[i]))) {
                ++i;
            } else {
                --j;
            }
        }
        return s;
    }

private:
    const string vowels_ = "aeiou";
    bool is_vowel(char a){
        return vowels_.find(a) != string::npos;
    }
};
