// Time:  O(l), l is the length of the number string
// Space: O(l)

class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num);
        int left = 0, right = 0;
        int max_idx = digits.length() - 1;
        for (int i = digits.length() - 1; i >= 0; --i) {
            if (digits[i] > digits[max_idx]) {
                max_idx = i;
            } else if (digits[max_idx] > digits[i]) {
                left = i;
                right = max_idx;
            }
        }
        swap(digits[left], digits[right]);
        return stoi(digits);
    }
};
