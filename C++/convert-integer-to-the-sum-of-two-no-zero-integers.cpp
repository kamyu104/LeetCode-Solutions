// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int curr = n;
        string digits;
        while (curr) { 
            if (curr % 10 == 0 ||
                (curr % 10 == 1 and curr != 1)) {
                digits.push_back('2');
                curr -= 10;  // carry
            } else {
                digits.push_back('1');
            }
            curr /= 10;
        }
        reverse(digits.begin(), digits.end());
        int a = stoi(digits);
        return {a, n - a};
    }
};

// Time:  O(nlogn)
// Space: O(logn)
class Solution2 {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        for (int a = 1; a < n; ++a) {
            if (to_string(a).find('0') == string::npos &&
                to_string(n - a).find('0') == string::npos) {
                result = {a, n - a};
                break;
            }
        }
        return result;
    }
};
