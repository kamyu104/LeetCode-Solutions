# Time:  O(nlogn)
# Space: O(n)

import collections


class Solution(object):
    def brightestPosition(self, lights):
        """
        :type lights: List[List[int]]
        :rtype: int
        """
        count = collections.Counter()
        for i, r in lights:
            count[i-r] += 1
            count[i+r+1] -= 1
        result = None
        max_cnt = cnt = 0
        for i, c in sorted(count.iteritems()):
            cnt += c
            if cnt > max_cnt:
                max_cnt, result = cnt, i
        return result
