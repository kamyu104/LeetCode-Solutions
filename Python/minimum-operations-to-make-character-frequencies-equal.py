# Time:  O(26 * n)
# Space: O(26)

# freq table, dp
class Solution(object):
    def makeStringGood(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        result = len(s)
        for f in xrange(min(x for x in cnt if x), max(cnt)+1):
            # dp1: min number of the last one of the operations is insert
            # dp2: min number of the last one of the operations is delete
            dp1 = dp2 = 0
            for i in xrange(26):
                if not cnt[i]:
                    continue
                if cnt[i] >= f:
                    new_dp1 = len(s)
                    new_dp2 = min(dp1, dp2)+(cnt[i]-f)
                else:
                    free = (cnt[i-1]-f if cnt[i-1] >= f else cnt[i-1]) if i-1 >= 0 else 0
                    new_dp1 = min(min(dp1, dp2)+(f-cnt[i]), dp2+max((f-cnt[i])-free, 0))
                    new_dp2 = min(dp1, dp2)+cnt[i]
                dp1, dp2 = new_dp1, new_dp2
            result = min(result, dp1, dp2)
        return result
