# Time:  O(nlogn)
# Space: O(1)

# sort, two pointers, sliding window
class Solution(object):
    def maxFrequencyScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        result = left = curr = 0
        for right in xrange(len(nums)):
            # "-+  " => "-0+ "
            # "-0+ " => "--++"
            curr += nums[right]-nums[(left+right)//2]
            if not curr <= k:
                # "--++" => " -0+"
                # " -0+" => "  -+"
                curr -= nums[((left+1)+right)//2]-nums[left]
                left += 1
        return right-left+1


# Time:  O(nlogn)
# Space: O(1)
# sort, two pointers, sliding window
class Solution2(object):
    def maxFrequencyScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        result = left = curr = 0
        for right in xrange(len(nums)):
            # "-+  " => "-0+ "
            # "-0+ " => "--++"
            curr += nums[right]-nums[(left+right)//2]
            while not curr <= k:
                # "--++" => " -0+"
                # " -0+" => "  -+"
                curr -= nums[((left+1)+right)//2]-nums[left]
                left += 1
            result = max(result, right-left+1)
        return result


# Time:  O(nlogn)
# Space: O(n)
# sort, prefix sum, binary search
class Solution3(object):
    def maxFrequencyScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def check(l):
            # "-+ " or "-0+"
            return any((prefix[i+l]-prefix[i+(l+1)//2])-(prefix[i+l//2]-prefix[i]) <= k for i in xrange(len(nums)-l+1))

        nums.sort()
        prefix = [0]*(len(nums)+1)
        for i, x in enumerate(nums):
            prefix[i+1] = prefix[i]+x
        left, right = 1, len(nums)
        while left <= right:
            mid = left+(right-left)//2
            if not check(mid):
                right = mid-1
            else:
                left = mid+1
        return right
