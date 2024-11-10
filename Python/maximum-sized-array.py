# Time:  precompute: O(max_s^(2/5))
#        runtime:    O(log(max_s))
# Space: O(max_s^(1/5))

import bisect 


# precompute, binary search
MAX_S = 10**15
i = 1
area = 0
vol = [0]
while vol[-1] <= MAX_S:
    area += 2*sum((i-1)|j for j in xrange(i))-((i-1)|(i-1))
    vol.append(((0+(i-1))*i//2)*area)
    i += 1
class Solution(object):
    def maxSizedArray(self, s):
        """
        :type s: int
        :rtype: int
        """
        return bisect.bisect_right(vol, s)-1
