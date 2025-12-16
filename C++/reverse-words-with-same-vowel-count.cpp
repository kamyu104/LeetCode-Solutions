// Time:  O(n)
// Space: O(1)

// string, inplace
class Solution {
public:
    string reverseWords(string s) {
        static const unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
        const auto& count = [&](int left, int right) {
            int result = 0;
            for (int i = left; i <= right; ++i) {
                result += VOWELS.count(s[i]);
            }
            return result;
        };

        for (int i = 0, l = 0, cnt = -1; i < size(s); ++i) {
            if (s[i] == ' ') {
                l = 0;
                continue;
            }
            ++l;
            if (i + 1 != size(s) && s[i + 1] != ' ') {
                continue;
            }
            const auto& c = count(i - l + 1, i);
            if (cnt == -1) {
                cnt = c;
            } else if (cnt == c) {
                reverse(begin(s) + i - l + 1, begin(s) + (i + 1));
            }
        }
        return s;
    }
};
