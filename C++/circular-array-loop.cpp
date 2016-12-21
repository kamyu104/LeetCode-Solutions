// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                continue;
            }
            int slow = i, fast = i;
            while (nums[next(nums, slow)] * nums[i] > 0 &&
                   nums[next(nums, fast)] * nums[i] > 0 &&
                   nums[next(nums, next(nums, fast))] * nums[i] > 0) {

                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
                if (slow == fast) {
                    if (slow == next(nums, slow)) {
                        break;
                    }
                    return true;
                }
            }
            slow = i;
            int val = nums[i];
            while (nums[slow] * val > 0) {
                int tmp = next(nums, slow);
                nums[slow] = 0;
                slow = tmp;
            }
        }
        return false;
    }

private:
    int next(const vector<int>& nums, int i) {
        return ((i + nums[i]) + nums.size()) % nums.size();
    }
};
