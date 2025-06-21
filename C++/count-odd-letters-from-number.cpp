// Time:  O(logn)
// Space: O(26)

// freq table
class Solution {
public:
    int countOddLetters(int n) {
        vector<string> lookup = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        vector<int> cnt(26);
        for (; n; n /= 10) {
            const int d = n % 10;
            for (const auto& x : lookup[d]) {
                ++cnt[x - 'a'];
            }
        }
        int result = 0;
        for (const auto& v : cnt) {
            result += v % 2;
        }
        return result;
    }
};
