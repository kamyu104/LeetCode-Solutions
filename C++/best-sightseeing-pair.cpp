// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int result = 0, curr = 0;
        for (const auto& x : A) {
            result = max(result, curr + x);
            curr = max(curr, x) - 1;
        }
        return result;
    }
};
