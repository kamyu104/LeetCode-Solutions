# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def earliestFullBloom(self, plantTime, growTime):
        """
        :type plantTime: List[int]
        :type growTime: List[int]
        :rtype: int
        """
        order = range(len(growTime))
        order.sort(key=lambda x: growTime[x], reverse=True)
        result = curr = 0
        for i in order:
            curr += plantTime[i]
            result = max(result, curr+growTime[i])
        return result
