// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int len = 0;
            for(; *s; ++s) {
                if (*s != ' ')
                    ++len;
                else if (*(s+1) && *(s+1) != ' ')
                    len = 0;
            }
            return len;
        }
};
