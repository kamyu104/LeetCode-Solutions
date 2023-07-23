// Time:  O(nlogn)
// Space: O(1)

// constructive algorithms, sort, greedy
class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(begin(usageLimits), end(usageLimits));
        int result = 0;
        int64_t curr = 0;
        for (const auto& x : usageLimits) {
            curr += x;
            if (curr >= result + 1) {
                curr -= result + 1;
                ++result;
            }
        }
        return result;
    }
};
