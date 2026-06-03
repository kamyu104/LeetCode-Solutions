// Time:  O(n)
// Space: O(n)

// hash table, prefix sum, greedy
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int ver = -1;
        vector<int> lookup(size(nums), ver);
        vector<int> suffix(size(nums));
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
        vector<int> result;
        ++ver;
        mex = 0;
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
            result.emplace_back(mex);
            ++ver;
            mex = 0;
            j = i + 1;
        }
        result.resize(size(result) + (size(nums) - j));
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// hash table, freq table, greedy
class Solution2 {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int ver = -1;
        vector<int> lookup(size(nums), ver);
        vector<int> cnt(size(nums));
        ++ver;
        int mex = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] < size(lookup)) {
                lookup[nums[i]] = ver;
                ++cnt[nums[i]];
            }
            while (mex < size(lookup) && lookup[mex] == ver) {
                ++mex;
            }
        }
        int suffix = mex, new_suffix = mex;
        vector<int> result;
        ++ver;
        mex = 0;
        int j = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (!suffix) {
                break;
            }
            if (nums[i] < size(lookup)) {
                lookup[nums[i]] = ver;
                if (!--cnt[nums[i]] && nums[i] < new_suffix) {
                    new_suffix = nums[i];
                }
            }
            while (mex < size(lookup) && lookup[mex] == ver) {
                ++mex;
            }
            if (mex != suffix) {
                continue;
            }
            result.emplace_back(mex);
            ++ver;
            mex = 0;
            j = i + 1;
            suffix = new_suffix;
        }
        result.resize(size(result) + (size(nums) - j));
        return result;
    }
};
