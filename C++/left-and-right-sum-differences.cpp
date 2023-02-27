// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        const int total = accumulate(cbegin(nums), cend(nums), 0);
        vector<int> result;
        int curr = 0;
        for (const auto& x : nums) {
            curr += x;
            result.emplace_back(abs((curr - x) - (total - curr)));
        }
        return result;
    }
};
