// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    string toHex(int num) {
        if (!num) {
            return "0";
        }

        string result;
        while (num && result.length() != sizeof(int) * 2) {
            int hex = num & 15;
            if (hex < 10) {
                result.push_back('0' + hex);
            } else {
                result.push_back('a' + hex - 10);
            }
            num >>= 4;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
