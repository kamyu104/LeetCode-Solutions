# Time:  O(n)
# Space: O(n)

class Solution(object):
    def maximumBeauty(self, flowers):
        """
        :type flowers: List[int]
        :rtype: int
        """
        lookup = {}
        prefix = [0]
        result = float("-inf")
        for i, f in enumerate(flowers):
            prefix.append(prefix[-1]+f if f > 0 else prefix[-1])
            if not f in lookup:
                lookup[f] = i
                continue
            result = max(result, 2*f+prefix[i+1]-prefix[lookup[f]] if f < 0 else prefix[i+1]-prefix[lookup[f]])
        return result
