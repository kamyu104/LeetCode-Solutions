// Time:  O(nlogn)
// Space: O(n)

// Divide and Conquer solution.
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sums(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countAndMergeSort(&sums, 0, sums.size(), lower, upper);
    }

    int countAndMergeSort(vector<long long> *sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) {  // The number of range [start, end) of which size is less than 2 is always 0.
            return 0;
        }
        int mid = start + (end - start) / 2;
        int count = countAndMergeSort(sums, start, mid, lower, upper) +
                    countAndMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, r = mid;
        vector<long long> tmp;
        for (int i = start; i < mid; ++i) {
            // Count the number of range sums that lie in [lower, upper].
            while (k < end && (*sums)[k] - (*sums)[i] < lower) {
                ++k;
            }
            while (j < end && (*sums)[j] - (*sums)[i] <= upper) {
                ++j;
            }
            count += j - k;

            // Merge the two sorted arrays into tmp.
            while (r < end && (*sums)[r] < (*sums)[i]) {
                tmp.emplace_back((*sums)[r++]);
            }
            tmp.emplace_back((*sums)[i]);
        }
        // Copy tmp back to sums.
        copy(tmp.begin(), tmp.end(), sums->begin() + start);
        return count;
    }
};
