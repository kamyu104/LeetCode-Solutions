# Time:  O(n)
# Space: O(1)

# combinatorics
class Solution(object):
    def countPermutations(self, complexity):
        """
        :type complexity: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def factorial(n):
            return reduce(lambda accu, x: (accu*x)%MOD, xrange(1, n+1), 1)

        return factorial(len(complexity)-1) if all(complexity[0] < complexity[i] for i in xrange(1, len(complexity))) else 0
