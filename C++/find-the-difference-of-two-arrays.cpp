// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        vector<unordered_set<int>> lookup = {{cbegin(nums1), cend(nums1)}, {cbegin(nums2), cend(nums2)}};
        for (int i = 0; i < 2; ++i) {
            for (const auto& x : lookup[i]) {
                if (!lookup[1 - i].count(x)) {
                    result[i].emplace_back(x);
                }
            }
        }
        return result;
    }
};
