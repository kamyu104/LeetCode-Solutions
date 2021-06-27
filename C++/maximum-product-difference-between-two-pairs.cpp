// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        vector<int> largest(2), smallest(2, numeric_limits<int>::max());
        for (const auto& x : nums) {
            if (x >= largest[0]) {
                largest[1] = largest[0];
                largest[0] = x;
            } else if (x > largest[1]) {
                largest[1] = x;
            }
            if (x <= smallest[0]) {
                smallest[1] = smallest[0];
                smallest[0] = x;
            } else if (x < smallest[1]) {
                smallest[1] = x;
            }
        }
        return largest[0] * largest[1] - smallest[0] * smallest[1];
    }
};
