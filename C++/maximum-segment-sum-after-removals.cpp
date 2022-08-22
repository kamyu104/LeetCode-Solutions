// Time:  O(nlogn)
// Space: O(n)

// prefix sum, bst
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        set<int> removed_idxs = {-1, static_cast<int>(size(nums))};
        vector<long long> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        multiset<long long> segments = {prefix.back()};
        vector<long long> result;
        for (const auto& q : removeQueries) {
            auto it = removed_idxs.emplace(q).first;
            const int left = *prev(it), right = *next(it);
            segments.erase(segments.find(prefix[right] - prefix[left + 1]));
            segments.emplace(prefix[q] - prefix[left + 1]);
            segments.emplace(prefix[right] - prefix[q + 1]);
            result.emplace_back(*rbegin(segments));
        }
        return result;
    }
};
