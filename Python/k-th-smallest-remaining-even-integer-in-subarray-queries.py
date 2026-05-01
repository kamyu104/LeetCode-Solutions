# Time:  O(n + qlogn)
# Space: O(n)

# prefix sum, binary search
class Solution(object):
    def kthRemainingInteger(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right
    
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+(1 if nums[i]%2 == 0 else 0)
        return [2*(k+(prefix[binary_search_right(l, r, lambda x: nums[x]//2 < k+(prefix[x+1]-prefix[l]))+1]-prefix[l])) for i, (l, r, k) in enumerate(queries)]
