# Time:  O(nlogn)
# Space: O(n)

import bisect


# prefix sum, binary search
class Solution(object):
    def totalScore(self, hp, damage, requirement):
        """
        :type hp: int
        :type damage: List[int]
        :type requirement: List[int]
        :rtype: int
        """
        prefix = [0]*(len(damage)+1)
        for i in xrange(len(prefix)-1):
            prefix[i+1] = prefix[i]+damage[i]
        result = 0
        for i in xrange(len(damage)):
            j = bisect.bisect_left(prefix, prefix[i+1]+requirement[i]-hp)
            if j <= i:
                result += i-j+1
        return result
