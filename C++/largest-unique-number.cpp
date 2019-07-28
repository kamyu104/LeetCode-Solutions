// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int, int> lookup;
        for (const auto& x : A) {
            ++lookup[x];
        }
        int result = -1;
        for (const auto& [k, v] : lookup) {
            if (v == 1) {
                result = max(result, k);
            }
        }
        return result;
    }
};
