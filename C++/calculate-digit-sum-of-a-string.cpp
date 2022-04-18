// Time:  O(n + n * (log10(9k)/k) + ... + k)
//      = O((n - (log10(9k)/k)*k)/(1-log10(9k)/k))
//      = O(n / (1-log10(9k)/k)) = O(n) for k >= 2
// Space: O(n)

// simulation
class Solution {
public:
    string digitSum(string s, int k) {
        while (size(s) > k) {
            string new_s;
            for (int i = 0, curr = 0; i < size(s); ++i) {
                curr += s[i] - '0';
                if (i % k == k - 1 || i == size(s) - 1) {
                    new_s += to_string(curr);
                    curr = 0;
                }
            }
            s = move(new_s);
        }
        return s;
    }
};
