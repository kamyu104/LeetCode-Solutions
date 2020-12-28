// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool halvesAreAlike(string s) {
        static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt1 = 0, cnt2 = 0;
        int left = 0, right = size(s) - 1;
        while (left < right) {
            cnt1 += vowels.count(s[left]);
            cnt2 += vowels.count(s[right]);
            ++left;
            --right;
        }
        return cnt1 == cnt2;
    }
};
