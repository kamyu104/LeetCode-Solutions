// Time:  O(n)
// Space: O(n)

// prefix sum
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        static const int INF = numeric_limits<int>::max();

        vector<int> right(size(nums), INF);
        for (int i = size(nums) - 1, curr = INF; i >= 0; --i) {
            right[i] = curr;
            curr = min(curr, nums[i]);
        }
        int result = INF;
        for (int i = 0, curr = INF; i < size(nums); ++i) {
            if (curr < nums[i] && nums[i] > right[i]) {
                result = min(result, curr + nums[i] + right[i]);
            }
            curr = min(curr, nums[i]);
        }
        return result != INF ? result : -1;
    }
};

// Time:  O(n)
// Space: O(n)
// prefix sum
class Solution2 {
public:
    int minimumSum(vector<int>& nums) {
        static const int INF = numeric_limits<int>::max();

        vector<int> left(size(nums), INF);
        for (int i = 0, curr = INF; i < size(nums); ++i) {
            left[i] = curr;
            curr = min(curr, nums[i]);
        }
        vector<int> right(size(nums), INF);
        for (int i = size(nums) - 1, curr = INF; i >= 0; --i) {
            right[i] = curr;
            curr = min(curr, nums[i]);
        }
        int result = INF;
        for (int i = 0; i < size(nums); ++i) {
            if (left[i] < nums[i] && nums[i] > right[i]) {
                result = min(result, left[i] + nums[i] + right[i]);
            }
        }
        return result != INF ? result : -1;
    }
};
