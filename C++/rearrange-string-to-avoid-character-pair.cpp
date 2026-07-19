// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        for (int left = 0, right = size(s) - 1; left < right;) {
            if (s[left] != x) {
                ++left;
                continue;
            }
            if (s[right] != y) {
                --right;
                continue;
            }
            swap(s[left++], s[right--]);
        }   
        return s;
    }
};
