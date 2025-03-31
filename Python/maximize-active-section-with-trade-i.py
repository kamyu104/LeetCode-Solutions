# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxActiveSectionsAfterTrade(self, s):
        """
        :type s: str
        :rtype: int
        """
        curr = prev = mx = cnt1 = 0
        for x in s:
            if x == '0':
                curr += 1
            else:
                if curr:
                    prev = curr
                    curr = 0
                cnt1 += 1
            mx = max(mx, prev+curr)
        return cnt1 if mx in (prev, curr) else mx+cnt1
