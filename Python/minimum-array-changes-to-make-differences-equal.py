# Time:  O(n + k)
# Space: O(k)

# prefix sum, difference array
class Solution(object):
    def minChanges(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        diff = [0]*((k+1)+1)
        def update(left, right, d):
            diff[left] += d
            diff[right+1] -= d

        for i in xrange(len(nums)//2):
            curr = abs(nums[i]-nums[~i])
            mx = max(nums[i]-0, k-nums[i], nums[~i]-0, k-nums[~i])
            # 1 change for i in range(0, curr)
            update(0, curr-1, 1)
            # 1 change for i in range(curr+1, mx+1)
            update(curr+1, mx, 1)
            # 2 changes for i in range(mx+1, k+1)
            update(mx+1, k, 2)
        result = len(nums)//2
        curr = 0
        for i in xrange(k+1):
            curr += diff[i]
            result = min(result, curr)
        return result
