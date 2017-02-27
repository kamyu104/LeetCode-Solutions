// Time:  O(nlogn)
// Space: O(logn)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return sortAndCount(nums.begin(), nums.end());
    }

private:
    int sortAndCount(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1) {
            return 0;
        }
        auto mid = begin + (end - begin) / 2;
        int count = sortAndCount(begin, mid) + sortAndCount(mid, end);
        for (auto i = begin, j = mid; i != mid; ++i) {
            while (j != end && *i > 2L * *j) {
                ++j;
            }
            count += j - mid;
        }
        inplace_merge(begin, mid, end);
        return count;
    }
};
