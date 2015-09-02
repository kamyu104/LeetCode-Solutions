// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Xor all the elements to get x ^ y.
        int x_xor_y = accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>());

        // Get the last bit where 1 occurs.
        x_xor_y &= -x_xor_y;

        // Get the subset of A where the number has the bit.
        // The subset only contains one of the two integers, call it x.
        // Xor all the elemets in the subset to get x.
        vector<int> result(2, 0);
        for (const auto& i : nums) {
            result[!(i & x_xor_y)] ^= i;
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Xor all the elements to get x ^ y.
        int x_xor_y = 0;
        for (const auto& i : nums) {
            x_xor_y ^= i;
        }

        // Get the last bit where 1 occurs.
        const auto bit = x_xor_y & ~(x_xor_y - 1);

        // Get the subset of A where the number has the bit.
        // The subset only contains one of the two integers, call it x.
        // Xor all the elemets in the subset to get x.
        int x = 0;
        for (const auto& i : nums) {
            if (i & bit) {
                x ^= i;
            }
        }

        return {x, x_xor_y ^ x};
    }
};
