// Time:  O(n^2)
// Space: O(n)

// brute force
class Solution {
public:
    string lexSmallest(string s) {
        string result = s;
        for (int k = 2; k <= size(s); ++k) {
            string t = s;
            reverse(begin(t), begin(t) + k);
            result = min(result, t);
        }
        for (int k = 2; k <= size(s); ++k) {
            string t = s;
            reverse(begin(t) + (size(t) - k), end(t));
            result = min(result, t);
        }
        return result;
    }
};
