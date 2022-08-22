# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def secondsToRemoveOccurrences(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = cnt = 0
        for c in s: 
            if c == '0':
                cnt += 1
                continue
            if cnt:
                result = max(result+1, cnt)
        return result 
