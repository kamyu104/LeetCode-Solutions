// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool hasAlternatingBits(int n) {
        auto curr = n % 2;
        n /= 2;
        while (n > 0) {
            if (curr == n % 2) {
                return false;
            }
            curr = n % 2;
            n /= 2;
        }
        return true; 
    }
};
