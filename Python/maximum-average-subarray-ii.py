# Time:  O(n)
# Space: O(n)

class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        def getDelta(avg, nums, k):
            accu = [0.0] * (len(nums) + 1)
            minval_pos = None
            delta = 0.0
            for i in xrange(len(nums)):
                accu[i+1] = nums[i] + accu[i] - avg
                if i >= (k-1):
                    if minval_pos == None or accu[i-k+1] < accu[minval_pos]:
                        minval_pos = i-k+1
                    if accu[i+1] - accu[minval_pos] >= 0:
                        delta = max(delta, (accu[i+1] - accu[minval_pos]) / (i+1 - minval_pos))
            return delta

        left, delta = min(nums), float("inf")
        while delta > 1e-5:
            delta = getDelta(left, nums, k)
            left += delta
        return left
