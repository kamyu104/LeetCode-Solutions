# Time:  O(n)
# Space: O(1)

# math
class Solution(object):
    def minimumCost(self, s, t, flipCost, swapCost, crossCost):
        """
        :type s: str
        :type t: str
        :type flipCost: int
        :type swapCost: int
        :type crossCost: int
        :rtype: int
        """
        cnt = [0]*2
        for i in xrange(len(s)):
            if s[i] == t[i]:
                continue
            cnt[ord(s[i])-ord('0')] += 1
        mn, mx = min(cnt[0], cnt[1]), max(cnt[0], cnt[1])
        q, r = divmod(mx-mn, 2)
        return mn*min(swapCost, 2*flipCost)+q*min(crossCost+swapCost, 2*flipCost)+r*flipCost


# Time:  O(n)
# Space: O(1)
# math
class Solution2(object):
    def minimumCost(self, s, t, flipCost, swapCost, crossCost):
        """
        :type s: str
        :type t: str
        :type flipCost: int
        :type swapCost: int
        :type crossCost: int
        :rtype: int
        """
        cnt = [0]*2
        for i in xrange(len(s)):
            if s[i] == t[i]:
                continue
            cnt[ord(s[i])-ord('0')] += 1
        mn, mx = min(cnt[0], cnt[1]), max(cnt[0], cnt[1])
        q, r = divmod(mx-mn, 2)
        return min((mx+mn)*flipCost, mn*swapCost+(mx-mn)*flipCost, mn*swapCost+q*(crossCost+swapCost)+r*flipCost)
