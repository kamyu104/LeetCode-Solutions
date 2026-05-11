# Time:  O(n)
# Space: O(1)

# greedy, case works
class Solution(object):
    def minFlips(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt0 = s.count('0')
        cnt1 = len(s)-cnt0
        return min(cnt0, max(cnt1-1, 0), max(cnt1-(s[0] == '1')-(s[-1] == '1'), 0))
