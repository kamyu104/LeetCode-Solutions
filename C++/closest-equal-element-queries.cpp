// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> dist(size(nums), size(nums));
        unordered_map<int, int> left;
        for (int i = 0; i < 2 * size(nums) - 1; ++i) {
            const auto& x = nums[i % size(nums)];
            if (left.count(x)) {
                dist[i % size(nums)] = min(dist[i % size(nums)], i - left[x]);
            }
            left[x] = i;
        }
        unordered_map<int, int> right;
        for (int i = 2 * size(nums) - 2; i >= 0; --i) {
            const auto& x = nums[i % size(nums)];
            if (right.count(x)) {
                dist[i % size(nums)] = min(dist[i % size(nums)], right[x] - i);
            }
            right[x] = i;
        }
        vector<int> result(size(queries), -1);
        for (int i = 0; i < size(queries); ++i) {
            if (dist[queries[i]] < size(nums)) {
                result[i] = dist[queries[i]];
            }
        }
        return result;
    }
};
