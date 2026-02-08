// Time:  O(n)
// Space: O(1)

// stack, simulation
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> result;
        for (long long x : nums) {
            while (!empty(result) && result.back() == x) {
                result.pop_back();
                x *= 2;
            }
            result.emplace_back(x);
        }
        return result;
    }
};
