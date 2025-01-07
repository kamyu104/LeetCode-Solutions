# Time:  O(n + 26)
# Space: O(n + 26)

# simulation, hash table, stack
class Solution(object):
    def calculateScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        lookup = [[] for _ in xrange(26)]
        for i, x in enumerate(s):
            x = ord(x)-ord('a')
            if lookup[25-x]:
                result += i-lookup[25-x].pop()
            else:
                lookup[x].append(i)
        return result
