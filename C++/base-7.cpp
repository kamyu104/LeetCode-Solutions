// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0) {
            return string("-").append(convertToBase7(-num));
        }
        string result;
        while (num) {
            result.append(to_string(num % 7));
            num /= 7;
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
};

class Solution2 {
public:
    string convertToBase7(int num) {
        if (num < 0) {
            return string("-").append(convertToBase7(-num));
        }
        if (num < 7) {
            return to_string(num);
        }
        return convertToBase7(num / 7).append(to_string(num % 7));
    }
};
