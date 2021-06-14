# Time:  O(n)
# Space: O(1)

class Solution(object):
    def mergeTriplets(self, triplets, target):
        """
        :type triplets: List[List[int]]
        :type target: List[int]
        :rtype: bool
        """
        result = [0]*3
        for t in triplets:
            if all(t[i] <= target[i] for i in xrange(3)):
                result = [max(result[i], t[i]) for i in xrange(3)]
        return result == target
