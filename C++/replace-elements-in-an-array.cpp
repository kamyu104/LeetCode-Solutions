// Time:  O(n + m)
// Space: O(n)

// hash table, optimized from solution2
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(nums); ++i) {
            lookup[nums[i]] = i;
        }
        for (const auto& op : operations) {
            int i = lookup[op[0]]; lookup.erase(op[0]);
            lookup[op[1]] = i;
        }
        for (const auto& [x, i] : lookup) {
            nums[i] = x;
        }
        return nums;
    }
};

// Time:  O(n + m)
// Space: O(n)
// hash table
class Solution2 {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(nums); ++i) {
            lookup[nums[i]] = i;
        }
        for (const auto& op : operations) {
            int i = lookup[op[0]]; lookup.erase(op[0]);
            nums[i] = op[1];
            lookup[nums[i]] = i;
        }
        return nums;
    }
};
