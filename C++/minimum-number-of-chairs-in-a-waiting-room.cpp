// Time:  O(n)
// Space: O(1)

// simulation
class Solution {
public:
    int minimumChairs(string s) {
        int result = 0, curr = 0;
        for (const auto& x : s) {
            curr += x == 'E' ? +1 : -1;
            result = max(result, curr);
        }
        return result;
    }
};
