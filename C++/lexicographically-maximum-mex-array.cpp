// Time:  O(n)
// Space: O(n)

// hash table, prefix sum, greedy
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        vector<int> suffix(size(nums));
        int ver = -1;
        vector<int> lookup(size(nums), ver);
        ++ver;
        int mex = 0;
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (nums[i] < size(lookup)) {
                lookup[nums[i]] = ver;
            }
            while (mex < size(lookup) && lookup[mex] == ver) {
                ++mex;
            }
            suffix[i] = mex;
        }
        ++ver;
        mex = 0;
        vector<int> result;
        int j = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (!suffix[j]) {
                break;
            }
            if (nums[i] < size(lookup)) {
                lookup[nums[i]] = ver;
            }
            while (mex < size(lookup) && lookup[mex] == ver) {
                ++mex;
            }
            if (mex != suffix[j]) {
                continue;
            }
            ++ver;
            mex = 0;
            result.emplace_back(suffix[j]);
            j = i + 1;
        }
        result.resize(size(result) + (size(nums) - j));
        return result;
    }
};
