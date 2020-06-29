// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        static const int MOD = 1e9 + 7;
        sort(begin(nums), end(nums));
        int result = 0;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                --right;
            } else {
                result = (result + pow(2, right - left, MOD)) % MOD;
                ++left;
            }
        }
        return result;
    }

private:
    uint64_t pow(uint64_t a,uint64_t b, uint64_t m) {
        a %= m;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }
};
