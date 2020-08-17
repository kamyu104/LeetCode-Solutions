# Time:  O((logn)^2)
# Space: O((logn)^2)

# complexity analysis: see https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/discuss/794847/Polylogarithmic-solution
class Solution(object):
    def minDays(self, n):
        """
        :type n: int
        :rtype: int
        """
        def memoization(lookup, i):
            if i <= 1:
                return i
            if i not in lookup:
                lookup[i] = 1+min(i%2+memoization(lookup, i//2),
                                  i%3+memoization(lookup, i//3))
            return lookup[i]

        lookup = {}
        return memoization(lookup, n)
