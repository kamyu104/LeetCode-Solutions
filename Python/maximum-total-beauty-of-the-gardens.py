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
        prefix = [0]*(len(partials)+1)
        for i in xrange(len(partials)):
            prefix[i+1] = prefix[i]+partials[i]
        suffix = [0]*(len(partials)+1)
        for i in reversed(xrange(len(partials))):
            suffix[i] = suffix[i+1]+partials[i]
        result = left = 0
        for right in xrange(len(partials)+1):
            total = newFlowers-((len(partials)-right)*target-suffix[right])
            if total < 0:
                continue
            while left+1 <= right and (left == 0 or (total+prefix[left])//left > partials[left]):
                left += 1
            mn = min((total+prefix[left])//left if left else 0, target-1)
            result = max(result, mn*partial+(len(flowers)-right)*full)
        return result
