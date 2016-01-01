// Time:  O(n)
// Space: O(1)

// Using virtual index solution.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int n = nums.size();
        int mid = (n - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        dutchFlagSort(nums, nums[mid]);
    }

    void dutchFlagSort(vector<int>& nums, int val) {
        #define Nums(i) nums[(1 + 2 * (i)) % N]
        for (int i = 0, j = 0, n = nums.size() - 1, N = nums.size() +  n % 2; j <= n;) {
            if (Nums(j) > val) {
                swap(Nums(i++), Nums(j++));
            } else if (Nums(j) < val) {
                swap(Nums(j), Nums(n--));
            } else {
                j++;
            }
        }
    }
};

// Time:  O(n)
// Space: O(n)
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
