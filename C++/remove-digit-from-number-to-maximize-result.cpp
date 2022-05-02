// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    string removeDigit(string number, char digit) {
        int i = 0;
        for (; i + 1 < size(number); ++i) {
            if (digit == number[i] && number[i] < number[i + 1]) {
                break;
            }
        }
        if (i + 1 == size(number)) {
            for (i = size(number) - 1; i >= 0; --i) {
                if (number[i] == digit) {
                    break;
                }
            }
        }
        number.erase(i, 1);
        return number;
    }
};
