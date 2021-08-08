// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minSwaps(string s) {
        int result = 0, curr = 0;
        for (const auto& c : s) {
            if (c == ']') {
               ++curr;
                result = max(result, curr);
            } else {
                --curr;
            }            
        }
        return (result + 1) / 2;
    }
};
