# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    # @return an integer
    def numDistinct(self, S, T):
        ways = [0 for _ in xrange(len(T) + 1)]
        ways[0] = 1
        for S_char in S:
            for j, T_char in reversed(list(enumerate(T))):
                if S_char == T_char:
                    ways[j + 1] += ways[j]
        return ways[len(T)]

