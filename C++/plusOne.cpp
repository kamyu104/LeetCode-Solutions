// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.cbegin(), digits.cend());
        int carry = 1;
        for (auto it = result.rbegin(); it != result.rend(); ++it) {
            *it += carry;
            carry = *it / 10;
            *it %= 10;
        }
        if (carry == 1) {
            result.emplace(result.begin(), carry);
        }
        return result;  
    }
};
