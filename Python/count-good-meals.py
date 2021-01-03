# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def countPairs(self, deliciousness):
        """
        :type deliciousness: List[int]
        :rtype: int
        """
        def floor_log2_x(x):
            return x.bit_length()-1

        MOD = 10**9+7
        max_pow = floor_log2_x(max(deliciousness))+1
        cnt = collections.Counter()
        result = 0
        for d in deliciousness:
            p = 1
            for i in xrange(max_pow+1):
                result = (result+cnt[p-d])%MOD
                p <<= 1
            cnt[d] += 1    
        return result
