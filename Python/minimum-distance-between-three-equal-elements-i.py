# Time:  O(n)
# Space: O(n)

import collections


# hash table, sliding window
class Solution(object):
    def minimumDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        INF = float("inf")
        result = INF
        lookup = collections.defaultdict(list)
        for i, x in enumerate(nums):
            lookup[x].append(i)
            if len(lookup[x]) < 3:
                continue
            result = min(result, 2*(i-lookup[x][-3]))  # k, j, i = lookup[x][:-3], (i-j)+(j-k)+(i-k) = 2*(i-k)
        return result if result != INF else -1
