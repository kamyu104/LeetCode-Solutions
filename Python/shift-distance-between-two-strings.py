# Time:  O(n + 26)
# Space: O(26)

# prefix sum
class Solution(object):
    def shiftDistance(self, s, t, nextCost, previousCost):
        """
        :type s: str
        :type t: str
        :type nextCost: List[int]
        :type previousCost: List[int]
        :rtype: int
        """
        prefix1 = [0]*(len(nextCost)+1)
        for i in xrange(len(nextCost)):
            prefix1[i+1] = prefix1[i]+nextCost[i]
        prefix2 = [0]*(len(previousCost)+1)
        for i in xrange(len(previousCost)):
            prefix2[i+1] = prefix2[i]+previousCost[i]
        result = 0
        for i in xrange(len(s)):
            if s[i] == t[i]:
                continue
            left = ord(s[i])-ord('a')
            right = ord(t[i])-ord('a')
            if left <= right:
                result += min(prefix1[right]-prefix1[left], prefix2[-1]-(prefix2[right+1]-prefix2[left+1]))
            else:
                result += min(prefix2[left+1]-prefix2[right+1], prefix1[-1]-(prefix1[left]-prefix1[right]))
        return result
