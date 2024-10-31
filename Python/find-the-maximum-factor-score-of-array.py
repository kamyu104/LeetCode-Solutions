# Time:  O(nlogr)
# Space: O(n)

# prefix sum
class Solution(object):
    def maxScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        def lcm(a, b):
            return a//gcd(a, b)*b

        right1 = [0]*(len(nums)+1)
        right2 = [0]*(len(nums)+1)
        right2[-1] = 1
        for i in reversed(xrange(len(nums))):
            right1[i] = gcd(right1[i+1], nums[i])
            right2[i] = lcm(right2[i+1], nums[i])
        result = right1[0]*right2[0]
        curr1, curr2 = 0, 1
        for i in xrange(len(nums)):
            result = max(result, gcd(curr1, right1[i+1])*lcm(curr2, right2[i+1]))
            curr1 = gcd(curr1, nums[i])
            curr2 = lcm(curr2, nums[i])
        return result
