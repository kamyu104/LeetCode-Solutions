# Time:  O(logn)
# Space: O(logn)

# math, combinatorics
class Solution(object):
    def countBinaryPalindromes(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = map(int, bin(n)[2:])
        l = len(s)
        return ((1<<(l//2))-1)+(n>>(l//2))+int(s[:(l+1)//2]+s[:l//2][::-1] <= s)
