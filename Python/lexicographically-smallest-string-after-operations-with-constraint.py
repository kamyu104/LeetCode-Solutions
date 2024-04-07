# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def getSmallestString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        result = map(lambda x: ord(x)-ord('a'), s)
        for i in xrange(len(result)):
            d = min(result[i]-0, 26-result[i])
            result[i] = 0 if d <= k else result[i]-k
            k -= min(d, k)
            if k == 0:
                break
        return "".join(map(lambda x: chr(x+ord('a')), result))
