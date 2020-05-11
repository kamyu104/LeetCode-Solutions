# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def countTriplets(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        count_sum = collections.defaultdict(lambda: [0, 0])
        count_sum[0] = [1, 0]
        result, prefix = 0, 0
        for i, x in enumerate(arr):
            prefix ^= x
            c, t = count_sum[prefix]
            # sum(i-(j+1) for j in index[prefix])
            # = len(index[prefix])*i - sum((j+1) for j in index[prefix])
            result += c*i - t
            count_sum[prefix] = [c+1, t+i+1]
        return result
