# Time:  O(n + l)
# Space: O(min(n, l))

import collections


# line sweep
class Solution(object):
    def meetRequirement(self, n, lights, requirement):
        """
        :type n: int
        :type lights: List[List[int]]
        :type requirement: List[int]
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        for p, r in lights:
            cnt[max(p-r, 0)] += 1
            cnt[min(p+r, n-1)+1] -= 1
        result = curr = 0
        for i, r in enumerate(requirement):
            curr += cnt.get(i, 0)
            if curr >= r:
                result += 1
        return result
