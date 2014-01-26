// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int c = 1;

            for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
                *it += c;
                c = *it / 10;
                *it %= 10;
            }

            if(c > 0) {
                digits.insert(digits.begin(), 1);
            }

            return digits;
        }
};
