# Time:  O(n)
# Space: O(n)

class Solution(object):
    def goodDaysToRobBank(self, security, time):
        """
        :type security: List[int]
        :type time: int
        :rtype: List[int]
        """
        right = [0]
        for i in reversed(xrange(1, len(security))):
            right.append(right[-1]+1 if security[i] >= security[i-1] else 0)
        right.reverse()
        result = []
        left = 0
        for i in xrange(len(security)):
            if left >= time and right[i] >= time:
                result.append(i)
            if i+1 < len(security):
                left = left+1 if security[i] >= security[i+1] else 0
        return result
