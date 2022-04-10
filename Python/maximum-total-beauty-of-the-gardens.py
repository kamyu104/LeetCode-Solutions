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
        flowers.sort()
        n = next((j for j in xrange(len(flowers)) if flowers[j] >= target), len(flowers))
        prefix = [0]*(n+1)
        for i in xrange(n):
            prefix[i+1] = prefix[i]+flowers[i]
        suffix = [0]*(n+1)
        for i in reversed(xrange(n)):
            suffix[i] = suffix[i+1]+flowers[i]
        result = left = 0
        for right in xrange(n+1):
            total = newFlowers-((n-right)*target-suffix[right])
            if total < 0:
                continue
            while left+1 <= right and (left == 0 or (total+prefix[left])//left > flowers[left]):
                left += 1
            mn = min((total+prefix[left])//left if left else 0, target-1)
            result = max(result, mn*partial+(len(flowers)-right)*full)
        return result
