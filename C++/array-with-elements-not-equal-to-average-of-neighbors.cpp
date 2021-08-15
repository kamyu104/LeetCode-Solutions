// Time:  O(n) ~ O(n^2), O(n) on average
// Space: O(1)

// Tri Partition (aka Dutch National Flag Problem) with virtual index solution
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int mid = (size(nums) - 1) / 2;
        nth_element(begin(nums), begin(nums) + mid, end(nums));  // O(n) ~ O(n^2) time
        reversedTriPartitionWithVI(nums, nums[mid]);  // O(n) time, O(1) space
        return nums;
    }

private:
    void reversedTriPartitionWithVI(vector<int>& nums, int val) {
        const int N = size(nums) / 2 * 2 + 1;
        #define Nums(i) nums[(1 + 2 * (i)) % N]
        for (int i = 0, j = 0, n = size(nums) - 1; j <= n;) {
            if (Nums(j) > val) {
                swap(Nums(i++), Nums(j++));
            } else if (Nums(j) < val) {
                swap(Nums(j), Nums(n--));
            } else {
                ++j;
            }
        }
    }
};

// Time:  O(nlogn)
// Space: O(n)
// Sorting and reorder solution
class Solution2 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int mid = (size(nums) - 1) / 2;
        sort(begin(nums), end(nums));  // O(nlogn) time
        vector<int> result(size(nums));  // O(n) space
        for (int i = 0, smallEnd = mid;  i < size(nums); i += 2, --smallEnd) {
            result[i] = nums[smallEnd];
        }
        for (int i = 1, largeEnd = size(nums) - 1; i < size(nums); i += 2, --largeEnd) {
            result[i] = nums[largeEnd];
        }
        return result;
    }
};
