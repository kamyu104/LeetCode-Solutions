// Time:  O(nlogn + qlogn)
// Space: O(1)

// greedy, sort, binary search
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums), end(nums));
        for (int i = 0; i + 1 < size(nums); ++i) {
            nums[i + 1] += nums[i];
        }
        vector<int> result;
        for (const auto& q : queries) {
            result.emplace_back(distance(cbegin(nums), upper_bound(cbegin(nums), cend(nums), q)));
        }
        return result;
    }
};
