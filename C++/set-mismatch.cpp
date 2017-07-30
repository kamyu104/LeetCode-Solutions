// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x_xor_y = 0;
        for (int i = 0; i < nums.size(); ++i) {
            x_xor_y ^= nums[i] ^ (i + 1);
        }
        int bit = x_xor_y & ~(x_xor_y - 1);
        vector<int> result(2);
        for (int i = 0; i < nums.size(); ++i) {
            result[static_cast<bool>(nums[i] & bit)] ^= nums[i];
            result[static_cast<bool>((i + 1) & bit)] ^= i + 1;
        }
        if (find(nums.begin(), nums.end(), result[0]) == nums.end()) {
            swap(result[0], result[1]);
        }
        return result;
    }
};


// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        for (const auto& i : nums) {
            if (nums[abs(i) - 1] < 0) {  // twice
                result[0] = abs(i);
            } else {
                nums[abs(i) - 1] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {  // missing
                result[1] = i + 1;
            } else {
                nums[i] *= -1;
            }
        }
        return result;
    }
};
