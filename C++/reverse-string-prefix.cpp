// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    string reversePrefix(string s, int k) {
        const auto& reverse = [](auto& s, int left, int right) {
            for (; left < right; ++left, --right) {
                swap(s[left], s[right]);
            }
        };

        reverse(s, 0, k - 1);
        return s;
    }
};


// Time:  O(n)
// Space: O(1)
// string
class Solution2 {
public:
    string reversePrefix(string s, int k) {
        reverse(begin(s), begin(s) + k);
        return s;
    }
};
