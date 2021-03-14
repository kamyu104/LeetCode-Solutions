// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int result = nums[k], curr = nums[k];
        int left = k, right = k;
        while (left - 1 >= 0 || right + 1 < size(nums)) {
            int l = (left - 1 >= 0 ? nums[left - 1] : 0);
            int r = (right + 1 < size(nums) ? nums[right + 1] : 0);
            if (l < r) { // choosing larger one to expand is always better than or equal to choosing smaller one
                ++right;
            } else {
                --left;
            }
            curr = min({curr, nums[left], nums[right]});
            result = max(result, curr * (right - left + 1));
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    int maximumScore(vector<int>& nums, int k) {
        int result = score(nums, k);
        reverse(begin(nums), end(nums));
        return max(result, score(nums, size(nums) - k - 1));
    }

private:
    int score(const vector<int>& nums, int k) {
        vector<int> prefix(k + 1, nums[k]);
        for (int i = k - 1; i >= 0; --i) {
            prefix[i] = min(prefix[i + 1], nums[i]);
        }
        int result = nums[k], right = nums[k];
        for (int j = k; j < size(nums); ++j) {
            right = min(right, nums[j]);
            const int i = distance(cbegin(prefix), lower_bound(cbegin(prefix), cend(prefix), right));
            if (i != size(prefix)) {
                result = max(result, right * (j - i + 1));
            }
        }
        return result;
    }
};
