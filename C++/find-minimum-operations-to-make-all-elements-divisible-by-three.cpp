// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for (const auto& x : nums) {
            if (x % 3 != 0) {
                ++result;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// math
class Solution2 {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for (const auto& x : nums) {
            result += min(x % 3, 3 - x % 3);
        }
        return result;
    }
};
