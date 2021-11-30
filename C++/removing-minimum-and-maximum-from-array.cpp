// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = count_if(cbegin(nums), cend(nums), [&](int n) { return n < target; });
        int equal = count(cbegin(nums), cend(nums), target);
        vector<int> result(equal);
        iota(begin(result), end(result), less);
        return result;
    }
};
