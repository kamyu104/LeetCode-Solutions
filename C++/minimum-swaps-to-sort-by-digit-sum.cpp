// Time:  O(nlogr + nlogn)
// Space: O(n)

// sort
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        const auto& total = [](int x) {
            int result = 0;
            for (; x; x /= 10) {
                result += x % 10;
            }
            return result;
        };

        vector<int> totals(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            totals[i] = total(nums[i]);
        }
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& i, const auto& j) {
            return pair(totals[i], nums[i]) < pair(totals[j], nums[j]);
        });
        vector<int> i_to_idx(size(idxs), -1);
        for (int i = 0; i < size(idxs); ++i) {
            i_to_idx[idxs[i]] = i;
        }
        int result = 0;
        vector<bool> lookup(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            int l = 0;
            while (!lookup[i]) {
                lookup[i] = true;
                ++l;
                i = i_to_idx[i];
            }
            result += max(l - 1, 0);
        }
        return result;
    }
};
