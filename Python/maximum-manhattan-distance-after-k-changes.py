# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxDistance(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        result = x = y = 0
        for i, c in enumerate(s, 1):
            if c == 'E':
                x += 1
            elif c == 'W':
                x -= 1
            elif c == 'N':
                y += 1
            elif c == 'S':
                y -= 1
            result = max(result, min(abs(x)+abs(y)+2*k, i))
        return result
