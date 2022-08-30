# Time:  O(n * l), l = max(g for g in garbage) = O(10)
# Space: O(1)

import collections


# simulation
class Solution(object):
    def garbageCollection(self, garbage, travel):
        """
        :type garbage: List[str]
        :type travel: List[int]
        :rtype: int
        """
        TYPES = "MPG"
        result = 0
        curr = [0]*3
        for i in xrange(len(garbage)):
            cnt = [0]*3
            for c in garbage[i]:
                cnt[TYPES.index(c)] += 1
            for j in xrange(len(TYPES)):
                if i-1 >= 0:
                    curr[j] += travel[i-1]
                if not cnt[j]:
                    continue
                result += cnt[j]+curr[j]
                curr[j] = 0
        return result
