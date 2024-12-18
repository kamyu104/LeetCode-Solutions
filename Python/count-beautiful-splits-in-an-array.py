# Time:  O(n^2)
# Space: O(n)

# z-function
class Solution(object):
    def beautifulSplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Template: https://cp-algorithms.com/string/z-function.html
        def z_function(s):  # Time: O(n), Space: O(n)
            z = [0]*len(s)
            l, r = 0, 0
            for i in xrange(1, len(z)):
                if i <= r:
                    z[i] = min(r-i+1, z[i-l])
                while i+z[i] < len(z) and s[z[i]] == s[i+z[i]]:
                    z[i] += 1
                if i+z[i]-1 > r:
                    l, r = i, i+z[i]-1
            return z

        result = 0
        z0 = z_function(nums)
        for i in xrange(1, len(nums)-1):
            zi = z_function(nums[i:])
            for j in xrange(i+1, len(nums)):
                if (z0[i] >= i and j-i >= i) or zi[j-i] >= j-i:
                    result += 1
        return result


# Time:  O(n^2)
# Space: O(n^2)
# dp
class Solution2(object):
    def beautifulSplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [[0]*len(nums) for _ in xrange(len(nums))]
        for i in reversed(xrange(len(nums))):
            for j in xrange(i+1, len(dp)):
                dp[i][j] = 1+(dp[i+1][j+1] if j+1 < len(nums) else 0) if nums[i] == nums[j] else 0
        result = 0
        for i in xrange(1, len(nums)-1):
            for j in xrange(i+1, len(nums)):
                if (dp[0][i] >= i and j-i >= i) or dp[i][j] >= j-i:
                    result += 1
        return result


# Time:  O(n^2)
# Space: O(n)
# z-function
class Solution_TLE(object):
    def beautifulSplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Template: https://cp-algorithms.com/string/z-function.html
        def z_function(s, left, right):  # Time: O(n), Space: O(n)
            z = [0]*(right-left+1)
            l, r = 0, 0
            for i in xrange(1, len(z)):
                if i <= r:
                    z[i] = min(r-i+1, z[i-l])
                while i+z[i] < len(z) and s[left+z[i]] == s[left+i+z[i]]:
                    z[i] += 1
                if i+z[i]-1 > r:
                    l, r = i, i+z[i]-1
            return z
        
        result = 0
        z0 = z_function(nums, 0, len(nums)-1)
        for i in xrange(1, len(nums)-1):
            zi = z_function(nums, i, len(nums)-1)
            for j in xrange(i+1, len(nums)):
                if (z0[i] >= i and j-i >= i) or zi[j-i] >= j-i:
                    result += 1
        return result
