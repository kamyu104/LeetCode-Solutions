// Time:  O(n)
// Space: O(b)

// greedy
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> lookup(cbegin(banned), cend(banned));
        int result = 0;
        for (int i = 1, total = 0; i <= n; ++i) {
            if (lookup.count(i)) {
                continue;
            }
            if (total + i > maxSum) {
                break;
            }
            total += i;
            ++result;
        }
        return result;
    }
};
