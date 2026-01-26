# Time:  O(n)
# Space: O(n)

# array
class Solution(object):
    def rotateElements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        def rotate(nums, k):
            k %= len(nums)
            c = gcd(len(nums), k)
            for i in xrange(c):
                for j in xrange(1, len(nums)//c):
                    nums[i], nums[(i-j*k)%len(nums)] = nums[(i-j*k)%len(nums)], nums[i]

        result = [x for x in nums if x >= 0]
        if not result:
            return nums
        rotate(result, k)
        j = 0
        for i in xrange(len(nums)):
            if nums[i] < 0:
                continue
            nums[i] = result[j]
            j += 1
        return nums


# Time:  O(n)
# Space: O(n)
# array
class Solution2(object):
    def rotateElements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        def reverse(nums, left, right):
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
    
        def rotate(nums, k):
            k %= len(nums)
            reverse(nums, 0, len(nums)-1)
            reverse(nums, 0, len(nums)-k-1)
            reverse(nums, len(nums)-k, len(nums)-1)

        result = [x for x in nums if x >= 0]
        if not result:
            return nums
        rotate(result, k)
        j = 0
        for i in xrange(len(nums)):
            if nums[i] < 0:
                continue
            nums[i] = result[j]
            j += 1
        return nums


# Time:  O(n)
# Space: O(n)
# array
class Solution3(object):
    def rotateElements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        def reverse(nums, left, right):
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
    
        def rotate(nums, k):
            k %= len(nums)
            nums[:] = nums[k:]+nums[:k]

        result = [x for x in nums if x >= 0]
        if not result:
            return nums
        rotate(result, k)
        j = 0
        for i in xrange(len(nums)):
            if nums[i] < 0:
                continue
            nums[i] = result[j]
            j += 1
        return nums
