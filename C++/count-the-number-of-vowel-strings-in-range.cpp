// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        static const unordered_set<int> VOWELS = {'a', 'e', 'i', 'o', 'u'};

        int result = 0;
        for (int i = left; i <= right; ++i) {
            if (VOWELS.count(words[i].front()) && VOWELS.count(words[i].back())) {
                ++result;
            }
        }
        return result;
    }
};
