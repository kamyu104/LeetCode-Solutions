// Time:  O(nlogn)
// Space: O(logn)

// brute force
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int result = 0;
        for (int i = num1; i <= num2; ++i) {
            const auto& s = to_string(i);
            for (int i = 1; i + 1 < size(s); ++i) {
                if ((s[i - 1] < s[i] && s[i] > s[i + 1]) || (s[i - 1] > s[i] && s[i] < s[i + 1])){
                    ++result;
                }
            }
        }
        return result;
    }
};
