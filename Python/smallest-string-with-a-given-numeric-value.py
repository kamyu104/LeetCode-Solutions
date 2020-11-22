# Time:  O(n)
# Space: O(1)

class Solution(object):
    def getSmallestString(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        MAX_DIFF = ord('z')-ord('a')

        k -= n
        result = ['a']*n
        for i in reversed(xrange(n)):
            tmp = min(k, MAX_DIFF)
            result[i] = chr(ord('a')+tmp)
            k -= tmp
            if k == 0:
                break
        return "".join(result)
