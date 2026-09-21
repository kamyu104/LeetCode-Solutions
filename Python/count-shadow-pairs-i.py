# Time:  O(n)
# Space: O(n)

import collections


# freq table, mono stack
class Solution(object):
    def shadowPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        stk = []
        cnt = collections.defaultdict(int)
        for x in nums:
            while stk and stk[-1] > x:
                cnt[stk.pop()] -= 1
            result += len(stk)-cnt[x]
            cnt[x] += 1
            stk.append(x)
        return result
