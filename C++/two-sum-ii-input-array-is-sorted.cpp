// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left != right) {
            const auto sum = numbers[left] + numbers[right];
            if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {0, 0};
    }
};
