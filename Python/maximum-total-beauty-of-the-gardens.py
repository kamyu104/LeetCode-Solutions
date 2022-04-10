# Time:  O(nlogn)
# Space: O(n)

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
        partials = sorted(x for x in flowers if x < target)
        prefix, suffix = 0, sum(partials)
        result = left = 0
        for right in xrange(len(partials)+1):
            total = newFlowers-((len(partials)-right)*target-suffix)
            if right < len(partials):
                suffix -= partials[right]
            if total < 0:
                continue
            while left+1 <= right and (left == 0 or (total+prefix)//left > partials[left]):
                prefix += partials[left]
                left += 1
            mn = min((total+prefix)//left if left else 0, target-1)
            result = max(result, mn*partial+(len(flowers)-right)*full)
        return result
