// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            } else if (!isalnum(s[j])) {
                --j;
            } else if (tolower(s[i]) != ::tolower(s[j])) {
                return false;
            } else {
                ++i, --j;
            }
        }
        return true;
    }
};

// Iterator solution.
class Solution2 {
public:    
    bool isPalindrome(string s) {
        auto left = s.begin();
        auto right = prev(s.end());
        for(; left < right;) { 
            if(!isalnum(*left)) {
                ++left;
            } else if(!isalnum(*right)) {
                --right; 
            } else if(::tolower(*left) != ::tolower(*right)) {
                return false;
            } else {
                ++left, --right;
            }
        }
        return true;
    }
};
