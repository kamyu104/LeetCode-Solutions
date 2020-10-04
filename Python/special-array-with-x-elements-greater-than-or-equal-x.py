# Time:  O(n)
# Space: O(1)

# counting sort solution
class Solution(object):
    def specialArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MAX_NUM = 1000
        count = [0]*(MAX_NUM+1)
        for num in nums:
            count[num] += 1
        n = len(nums)
        for i in xrange(len(count)):
            if i == n:
                return i
            n -= count[i]
        return -1


# Time:  O(n)
# Space: O(1)
# counting sort + binary search solution
class Solution2(object):
    def specialArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MAX_NUM = 1000
        def counting_sort(nums, reverse=False):  # Time: O(n)
            count = [0]*(MAX_NUM+1)
            for num in nums:
                count[num] += 1
            for i in xrange(1, len(count)):
                count[i] += count[i-1]
            result = [0]*len(nums)
            for num in reversed(nums):  # stable sort
                result[count[num]-1] = num
                count[num] -= 1
            if reverse:
                result.reverse()
            return result
    
        nums = counting_sort(nums, reverse=True)
        left, right = 0, len(nums)-1
        while left <= right:  # Time: O(logn)
            mid = left + (right-left)//2
            if nums[mid] <= mid:
                right = mid-1
            else:
                left = mid+1
        return -1 if left < len(nums) and left == nums[left] else left


# Time:  O(nlogn)
# Space: O(1)
# sort solution
class Solution3(object):
    def specialArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort(reverse=True)  # Time: O(nlogn)
        for i in xrange(len(nums)):  # Time: O(n)
            if nums[i] <= i:
                break
        else:
            i += 1
        return -1 if i < len(nums) and i == nums[i] else i
