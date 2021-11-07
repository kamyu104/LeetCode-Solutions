// Time:  O(n)
// Space: O(1)

class Solution {
public:
    long long countVowels(string word) {
        static const unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

        int64_t result = 0;
        for (int i = 0; i < size(word); ++i) {
            if (VOWELS.count(word[i])) {
                result += (i - 0 + 1)* ((size(word) - 1) - i + 1);
            }
        }
        return result;
    }
};
