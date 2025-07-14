// Time:  O(n)
// Space: O(1)

// simulation
class Solution {
public:
    int totalReplacements(vector<int>& ranks) {
        int result = -1;
        int mn = numeric_limits<int>::max();
        for (const auto& x : ranks) {
            if (x >= mn) {
                continue;
            }
            mn = x;
            ++result;
        }
        return result;
    }
};
