// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0, count = 0;     
        for (const auto& c : s) {
            count += (c == 'L') ? 1 : -1;            
            if (count == 0) {
                ++result;
            }
        }
        return result;
    }
};
