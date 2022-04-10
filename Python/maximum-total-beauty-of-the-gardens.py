# Time:  O(nlogn)
# Space: O(1)

import bisect


# sort, prefix sum, greedy, two pointers
class Solution(object):
    def maximumBeauty(self, flowers, newFlowers, target, full, partial):
        """
        :type flowers: List[int]
        :type newFlowers: int
        :type target: int
        :type full: int
        :type partial: int
        :rtype: int
        """
        flowers.sort()
        n = bisect.bisect_left(flowers, target)
        prefix, suffix = 0, sum(flowers[i] for i in xrange(n))
        result = left = 0
        for right in xrange(n+1):
            total = newFlowers-((n-right)*target-suffix)
            if right < n:
                suffix -= flowers[right]
            if total < 0:
                continue
            while left+1 <= right and (left == 0 or (total+prefix)//left > flowers[left]):
                prefix += flowers[left]
                left += 1
            mn = min((total+prefix)//left if left else 0, target-1)
            result = max(result, mn*partial+(len(flowers)-right)*full)
        return result
