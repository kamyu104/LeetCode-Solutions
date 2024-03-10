# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def maximumHappinessSum(self, happiness, k):
        """
        :type happiness: List[int]
        :type k: int
        :rtype: int
        """
        happiness.sort(reverse=True)
        return sum(max(happiness[i]-i, 0) for i in xrange(k))
