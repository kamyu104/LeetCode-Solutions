# Time:  O(n)
# Space: O(1)

class Solution(object):
    def shuffle(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: List[int]
        """
        def dest(i, n):
            return 2*i if i < n else 2*(i-n)+1
    
        for i in xrange(len(nums)):
            if nums[i] < 0:
                continue
            j = i
            while True:
                j = dest(j, n)
                nums[i], nums[j] = nums[j], nums[i]
                nums[j] = -nums[j]
                if i == j:
                    break
        for i in xrange(len(nums)):
            nums[i] = -nums[i]
        return nums
