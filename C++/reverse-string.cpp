// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void reverseString(vector<char>&  s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
