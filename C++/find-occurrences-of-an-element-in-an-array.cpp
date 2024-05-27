// Time:  O(n + q)
// Space: O(n)

// array
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> lookup;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] != x) {
                continue;
            }
            lookup.emplace_back(i);
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            result[i] = queries[i] - 1 < size(lookup) ? lookup[queries[i] - 1] : -1;
        }
        return result;
    }
};
