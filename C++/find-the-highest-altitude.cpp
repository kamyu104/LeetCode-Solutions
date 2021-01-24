// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0, curr = 0;
        for (const auto& g : gain) {
            curr += g;
            result = max(result, curr);
        }
        return result;
    }
};
