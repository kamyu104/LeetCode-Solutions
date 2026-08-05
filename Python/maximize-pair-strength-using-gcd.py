# Time:  O(n^2 * logr)
# Space: O(1)

# brute force, pruning
class Solution(object):
    def maxPairStrength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a
    
        nums.sort(reverse=True)
        result = 0
        for i in xrange(len(nums)):
            for j in xrange(i+1, len(nums)):
                if nums[i]*nums[j] <= result:
                    break
                result = max(result, nums[i]*nums[j]//(gcd(nums[i], nums[j])**2))
        return result


# Time:  O(n^2 * logr)
# Space: O(1)
# brute force
class Solution2(object):
    def maxPairStrength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a
    
        return max(nums[i]*nums[j]//(gcd(nums[i], nums[j])**2) for i in xrange(len(nums)) for j in xrange(i+1, len(nums)))
