// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    string reverseByType(string s) {
        const auto& reverse = [](auto& s, const auto& check) {
            for (int left = 0, right = size(s) - 1; left < right; ) {
                if (!check(s[left])) {
                    ++left;
                } else if (!check(s[right])) {
                    --right;
                } else {
                    swap(s[left], s[right]);
                    ++left;
                    --right;
                }
            }
        };

        reverse(s, [](const auto& x) {
            return isalpha(x);
        });
        reverse(s, [](const auto& x) {
            return !isalpha(x);
        });
        return s;
    }
};
