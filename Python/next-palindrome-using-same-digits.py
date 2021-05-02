# Time:  O(n)
# Space: O(1)

class Solution(object):
    def nextPalindrome(self, num):
        """
        :type num: str
        :rtype: str
        """
        def next_permutation(nums, begin, end):
            def reverse(nums, begin, end):
                left, right = begin, end-1
                while left < right:
                    nums[left], nums[right] = nums[right], nums[left]
                    left += 1
                    right -= 1

            k, l = begin-1, begin
            for i in reversed(xrange(begin, end-1)):
                if nums[i] < nums[i+1]:
                    k = i
                    break
            else:
                reverse(nums, begin, end)
                return False
            for i in reversed(xrange(k+1, end)):
                if nums[i] > nums[k]:
                    l = i
                    break
            nums[k], nums[l] = nums[l], nums[k]
            reverse(nums, k+1, end)
            return True
        
        nums = list(num)
        if not next_permutation(nums, 0, len(nums)//2):
            return ""
        for i in xrange(len(nums)//2):
            nums[-1-i] = nums[i]
        return "".join(nums)
