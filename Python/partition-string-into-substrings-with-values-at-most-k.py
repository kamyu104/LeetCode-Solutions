# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minimumPartition(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        result = 1
        curr = 0
        for c in s:
            if int(c) > k:
                return -1
            if curr*10+int(c) > k:
                result += 1
                curr = 0
            curr = curr*10+int(c)
        return result
