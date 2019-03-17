# Time:  O(nlogr)
# Space: O(1)

class Solution(object):
    def shipWithinDays(self, weights, D):
        """
        :type weights: List[int]
        :type D: int
        :rtype: int
        """
        def possible(weights, D, mid):
            result, curr = 1, 0
            for w in weights:
                if curr+w > mid:
                    result += 1
                    curr = 0
                curr += w
            return result <= D
    
        left, right = max(weights), sum(weights)
        while left <= right:
            mid = left + (right-left)//2
            if possible(weights, D, mid):
                right = mid-1
            else:
                left = mid+1
        return left
