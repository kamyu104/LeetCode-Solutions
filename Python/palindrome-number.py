from __future__ import print_function
# Time:  O(1)
# Space: O(1)

class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x < 0:
            return False
        copy, reverse = x, 0

        while copy:
            reverse *= 10
            reverse += copy % 10
            copy //= 10

        return x == reverse

if __name__ == "__main__":
    print(Solution().isPalindrome(12321))
    print(Solution().isPalindrome(12320))
    print(Solution().isPalindrome(-12321))

