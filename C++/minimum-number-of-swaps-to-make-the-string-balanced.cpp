// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minSwaps(string s) {
        int result = 0, curr = 0;
        for (const auto& c : s) {
            curr = (c == ']') ? curr + 1 : curr - 1;
            result = max(result, curr);
        }
        return (result + 1) / 2;
    }
};
