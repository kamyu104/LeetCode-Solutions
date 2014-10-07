# Time:  O(n)
# Space: O(1)
#
# Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
# 
# For example,
# "A man, a plan, a canal: Panama" is a palindrome.
# "race a car" is not a palindrome.
# 
# Note:
# Have you consider that the string might be empty? This is a good question to ask during an interview.
# 
# For the purpose of this problem, we define empty string as valid palindrome.
#

class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        i, j = 0, len(s) - 1
        while i < j:
            while i < j and not (s[i].isalpha() or s[i].isdigit()):
                i += 1
            while i < j and not (s[j].isalpha() or s[j].isdigit()):
                j -= 1
            if s[i].lower() != s[j].lower():
                return False
            i, j = i + 1, j - 1
        return True

if __name__ == "__main__":
    print Solution().isPalindrome("A man, a plan, a canal: Panama")