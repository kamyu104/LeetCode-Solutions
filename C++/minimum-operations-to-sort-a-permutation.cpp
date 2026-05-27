// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const auto& check = [&](int i, int d) {
            for (int j = 0; j < size(nums); ++j) {
                if (nums[((i + j * d) + size(nums)) % size(nums)] != j) {
                    return false;
                }
            }
            return true;
        };

        const auto& idx = distance(cbegin(nums), find(cbegin(nums), cend(nums), 0));
        if (check(idx, +1)) {
            return min(idx, 1 + (static_cast<int>(size(nums)) - idx) + 1);
        } else if (check(idx, -1)) {
            return min((idx + 1) + 1, 1 + (static_cast<int>(size(nums)) - (idx + 1)));
        }
        return -1;
    }
};
