from __future__ import print_function
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        i, j = 0, len(s) - 1
        while i < j:
            while i < j and not s[i].isalnum():
                i += 1
            while i < j and not s[j].isalnum():
                j -= 1
            if s[i].lower() != s[j].lower():
                return False
            i, j = i + 1, j - 1
        return True

if __name__ == "__main__":
    print(Solution().isPalindrome("A man, a plan, a canal: Panama"))

