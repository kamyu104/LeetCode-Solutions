// Time:  O(n) ~ O(n^2)
// Space: O(1)

// Tri Partition (aka Dutch National Flag Problem) with virtual index solution. (44ms)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int mid = (nums.size() - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());  // O(n) ~ O(n^2) time
        reversedTriPartitionWithVI(nums, nums[mid]);  // O(n) time, O(1) space
    }

    void reversedTriPartitionWithVI(vector<int>& nums, int val) {
        const int N = nums.size() / 2 * 2 + 1;
        #define Nums(i) nums[(1 + 2 * (i)) % N]
        for (int i = 0, j = 0, n = nums.size() - 1; j <= n;) {
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

// Time:  O(n) ~ O(n^2)
// Space: O(n)
// Tri Partition (aka Dutch National Flag Problem) solution. (64ms)
class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        int mid = (nums.size() - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());  // O(n) ~ O(n^2) time
        triPartition(nums, nums[mid]);  // O(n) time, O(1) space

        vector<int> res(nums.size());  // O(n) space
        for (int i = 0, smallEnd = mid;  i < nums.size(); i += 2, --smallEnd) {
            res[i] = nums[smallEnd];
        }
        for (int i = 1, largeEnd = nums.size() - 1; i < nums.size(); i += 2, --largeEnd) {
            res[i] = nums[largeEnd];
        }
        nums = res;
    }

    void triPartition(vector<int>& nums, int val) {
        for (int i = 0, j = 0, n = nums.size() - 1; j <= n;) {
            if (nums[j] < val) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] > val) {
                swap(nums[j], nums[n--]);
            } else {
                ++j;
            }
        }
    }
};

// Time:  O(nlogn)
// Space: O(1)
// Sorting and Tri Partition (aka Dutch National Flag Problem) with virtual index solution. (64ms)
class Solution3 {
public:
    void wiggleSort(vector<int>& nums) {
        int mid = (nums.size() - 1) / 2;
        sort(nums.begin(), nums.end());  // O(nlogn) time
        reversedTriPartitionWithVI(nums, nums[mid]);  // O(n) time, O(1) space
    }

    void reversedTriPartitionWithVI(vector<int>& nums, int val) {
        const int N = nums.size() / 2 * 2 + 1;
        #define Nums(i) nums[(1 + 2 * (i)) % N]
        for (int i = 0, j = 0, n = nums.size() - 1; j <= n;) {
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
// Sorting and reorder solution. (64ms)
class Solution4 {
public:
    void wiggleSort(vector<int>& nums) {
        int mid = (nums.size() - 1) / 2;
        sort(nums.begin(), nums.end());  // O(nlogn) time
        vector<int> res(nums.size());  // O(n) space
        for (int i = 0, smallEnd = mid;  i < nums.size(); i += 2, --smallEnd) {
            res[i] = nums[smallEnd];
        }
        for (int i = 1, largeEnd = nums.size() - 1; i < nums.size(); i += 2, --largeEnd) {
            res[i] = nums[largeEnd];
        }
        nums = res;
    }
};
