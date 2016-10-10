// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int count = 0;
        vector<int> top(3, numeric_limits<int>::min());

        for (const auto& num : nums) {
            if (num > top[0]) {
                top[2] = top[1];
                top[1] = top[0];
                top[0] = num;
                ++count;
            } else if (num != top[0] && num > top[1]) {
                top[2] = top[1];
                top[1] = num;
                ++count;
            } else if (num != top[0] && num != top[1] && num >= top[2]) {
                top[2] = num;
                ++count;
            }
        }

        if (count < 3) { 
            return top[0];
        }
        return top[2];
    }
};
