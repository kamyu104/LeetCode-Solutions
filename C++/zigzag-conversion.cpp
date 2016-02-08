// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        const int step = 2 * numRows - 2;
        string zigzag;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.length(); j += step) {
                zigzag.push_back(s[j]);
                if (0 < i && i < numRows - 1 &&
                    j + step - 2 * i < s.length()) {
                    zigzag.push_back(s[j + step - 2 * i]);
                }
            }
        }
        return zigzag;
    }
};
