// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0)
                return false;

            int d = 1;
            for(; x / d >= 10 ; d *= 10);

            for(; x > 0; x = (x % d) / 10, d /= 100) {
                int q = x / d;
                int r = x % 10;
                if(q != r)
                    return false;
            }

            return true;
        }
};
