// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int maximum69Number (int num) {
        int change = 0;
        for (int curr = num, base = 3; curr; base *= 10, curr /= 10) {
            if (curr % 10 == 6) {
                change = base;
            }
        }
        return num + change;
    }
};

// Time:  O(logn)
// Space: O(logn)
class Solution2 {
public:
    int maximum69Number (int num) {
        auto s = to_string(num);
        auto i = s.find('6');
        if (i != string::npos) {
            s[i] = '9';
        }
        return stoi(s);
    }
};
