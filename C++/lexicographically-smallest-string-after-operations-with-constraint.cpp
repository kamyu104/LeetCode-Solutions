// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    string getSmallestString(string s, int k) {
        for (auto& x : s) {
            const int d = min(x - 'a', ('a' + 26) - x);
            x = d <= k ? 'a' : x - k;
            k -= min(d, k);
            if (k == 0) {
                break;
            }
        }
        return s;
    }
};
