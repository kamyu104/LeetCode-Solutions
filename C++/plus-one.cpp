// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.rbegin(), digits.rend());
        int carry = 1;
        for (auto& num : result) {
            num += carry;
            carry = num / 10;
            num %= 10;
        }
        if (carry == 1) {
            result.emplace_back(carry);
        }
        reverse(result.begin(), result.end());
        return result;  
    }
};
