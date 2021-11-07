// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countVowelSubstrings(string word) {
        static const unordered_set<int> VOWELS = {'a', 'e', 'i', 'o', 'u'};

        unordered_map<int, int> cnt;
        int result = 0;
        for (int i = 0, j = 0, k = 0; i < size(word); ++i) {
            if (!VOWELS.count(word[i])) {
                cnt = unordered_map<int, int>();
                j = k = i + 1;
                continue;
            }
            ++cnt[word[i]];
            for (; size(cnt) == 5; ++k) {
                --cnt[word[k]];
                if (!cnt[word[k]]) {
                    cnt.erase(word[k]);
                }
            }
            result += k - j;
        }
        return result;
    }
};
