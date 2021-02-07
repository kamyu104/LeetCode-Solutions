# Time:  O(1)
# Space: O(1)

class Solution(object):
    def maximumScore(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        # assumed c is the max size
        # case1: a+b > c
        # => (a+b-c)//2 + c = (a+b+c)//2 < a+b
        # case2: a+b <= c
        # => a+b <= (a+b+c)//2
        return min((a+b+c)//2, a+b+c - max(a, b, c))
