# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minimumCost(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def topk(a, k):
            result = [float("inf")]*k
            for x in a:
                for i in xrange(len(result)):
                    if x < result[i]:
                        result[i], x = x, result[i]
            return result

        return nums[0]+sum(topk((nums[i] for i in xrange(1, len(nums))), 2))
