// Time:  O(n)
// Space: O(n)

// freq table, prefix sum
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        const int idx = distance(cbegin(nums), find(cbegin(nums), cend(nums), k));
        unordered_map<int, int> lookup;
        for (int i = idx, curr = 0; i >= 0; --i) {
            curr += nums[i] == k ? 0 : (nums[i] < k ? -1 : +1);
            ++lookup[curr];
        }
        int result = 0;
        for (int i = idx, curr = 0; i < size(nums); ++i) {
            curr += nums[i] == k ? 0 : (nums[i] < k ? -1 : +1);
            result += lookup[-curr] + lookup[-(curr - 1)];
        }
        return result;
    }
};
