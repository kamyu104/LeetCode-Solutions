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
                cnt.clear();
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

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int countVowelSubstrings(string word) {
        static const int k = 5;

        return atMostK(word, k) - atMostK(word, k - 1);
    }

private:
    int atMostK(const string& word, int k) {
        static const unordered_set<int> VOWELS = {'a', 'e', 'i', 'o', 'u'};

        unordered_map<int, int> cnt;
        int result = 0, left = 0;
        for (int right = 0; right < size(word); ++right) {
            if (!VOWELS.count(word[right])) {
                cnt.clear();
                left = right + 1;
                continue;
            }
            ++cnt[word[right]];
            while (size(cnt) > k) {
                if (!--cnt[word[left]]) {
                    cnt.erase(word[left]);
                }
                ++left;
            }
            result += right - left + 1;
        }
        return result;
    }
};
