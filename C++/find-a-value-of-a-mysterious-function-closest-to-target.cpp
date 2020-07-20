// Time:  O(nlogm), m is the max value of arr
// Space: O(logm)

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int result = numeric_limits<int>::max();
        unordered_set<int> dp;  // at most O(logm) dp states
        for (const auto& x : arr) {
            unordered_set<int> new_dp = {x};
            for (const auto& f: dp) {
                new_dp.emplace(f & x);
            }
            for (const auto& f : new_dp) {
                result = min(result, abs(f - target));
            }
            dp = move(new_dp);
        }
        return result;
    }
};
