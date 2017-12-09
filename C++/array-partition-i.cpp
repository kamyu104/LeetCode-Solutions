// Time:  O(r), r is the range size of the integers
// Space: O(r)

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        const auto LEFT = -10000;
        const auto RIGHT = 10000;
        vector<int> lookup(RIGHT - LEFT + 1, 0);
        for (const auto& num: nums) {
            ++lookup[num - LEFT];
        }
        auto r = 0, result = 0;
        for (int i = LEFT; i <= RIGHT; ++i) {
            result += (lookup[i - LEFT] + 1 - r) / 2 * i;
            r = (lookup[i - LEFT] + r) % 2;
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto result = 0;
        for (auto i = 0; i < nums.size(); i += 2) {
            result += nums[i];
        }
        return result;
    }
};
