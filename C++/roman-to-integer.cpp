// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> numeral_map = {{'I',    1}, {'V',   5}, {'X',  10},
                                                {'L',   50}, {'C', 100}, {'D', 500},
                                                {'M', 1000}};
        int decimal = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && numeral_map[s[i]] > numeral_map[s[i - 1]]) {
                decimal += numeral_map[s[i]] - 2 * numeral_map[s[i - 1]];
            } else {
                decimal += numeral_map[s[i]];
            }
        }
        return decimal;
    }
};
