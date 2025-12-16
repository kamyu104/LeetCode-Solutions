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

        for (int right = 0, left = 0, cnt = -1; right < size(s); ++right) {
            if (right - 1 < 0 || s[right - 1] == ' ') {
                left = right;
            }
            if (right + 1 != size(s) && s[right + 1] != ' ') {
                continue;
            }
            const auto& c = count(left, right);
            if (cnt == -1) {
                cnt = c;
            } else if (cnt == c) {
                reverse(begin(s) + left, begin(s) + (right + 1));
            }
        }
        return s;
    }
};
