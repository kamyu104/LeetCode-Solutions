// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string intToRoman(int num) {
        const vector<int> nums{1000, 900, 500, 400, 100, 90,
                               50, 40, 10, 9, 5, 4, 1};
        const vector<string> romans{"M", "CM", "D", "CD", "C", "XC", "L",
                                    "XL", "X", "IX", "V", "IV", "I"};

        string result;
        int i = 0;
        while (num > 0) {
            int times = num / nums[i];
            while (times--) {
                num -= nums[i];
                result.append(romans[i]);
            }
            ++i;
        }        
        return result;
    }
};
