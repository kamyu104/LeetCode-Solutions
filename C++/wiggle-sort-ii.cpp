// Time:  O(n) ~ O(n^2)
// Space: O(1)

// Dutch flag sorting with virtual index solution.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int mid = (nums.size() - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        reversedDutchFlagSortWithVI(nums, nums[mid]);
    }

    void reversedDutchFlagSortWithVI(vector<int>& nums, int val) {
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
// Dutch flag sorting solution.
class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        const int n = nums.size();
        int mid = (n - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        dutchFlagSort(nums, nums[mid]);

        vector<int> res(n);
        for (int i = 0, smallEnd = mid;  i < n; i += 2, --smallEnd) {
            res[i] = nums[smallEnd];
        }
        for (int i = 1, largeEnd = n - 1; i < n; i += 2, --largeEnd) {
            res[i] = nums[largeEnd];
        }
        nums = res;
    }

    void dutchFlagSort(vector<int>& nums, int val) {
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
