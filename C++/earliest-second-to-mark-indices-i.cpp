// Time:  O(mlogm)
// Space: O(n)

// binary search, greedy
class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        const auto& check = [&](int t) {
            vector<int> lookup(size(nums), -1);
            for (int i = 0; i < t; ++i) {
                lookup[changeIndices[i] - 1] = i;
            }
            if (count(cbegin(lookup), cend(lookup), -1)) {
                return false;
            }
            for (int i = 0, cnt = 0; i < t; ++i) {
                if (i != lookup[changeIndices[i] - 1]) {
                    ++cnt;
                    continue;
                }
                cnt -= nums[changeIndices[i] - 1];
                if (cnt < 0) {
                    return false;
                }
            }
            return true;
        };

        int64_t left = accumulate(cbegin(nums), cend(nums), 0ll) + size(nums), right = size(changeIndices);
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left <= size(changeIndices) ? left : -1;
    }
};
