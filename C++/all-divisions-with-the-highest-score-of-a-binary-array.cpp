// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        const int total = accumulate(cbegin(nums), cend(nums), 0);
        vector<int> result;
        for (int i = 0, zeros = 0, mx = 0; i <= size(nums); ++i) {
            zeros += static_cast<int>(((i - 1 >= 0) ? nums[i - 1] : 0) == 0);
            if (zeros + (total - (i - zeros)) > mx) {
                mx = zeros + (total - (i - zeros));
                result.clear();
            }
            if (zeros + (total - (i - zeros)) == mx) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
