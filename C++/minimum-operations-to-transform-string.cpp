// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minOperations(string s) {
        int result = 0;
        for (const auto& x : s) {
            result = max(result, (26 - (x - 'a')) % 26);
        }
        return result;
    }
};
