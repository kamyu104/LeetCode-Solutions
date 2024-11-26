# Time:  O(nlogn)
# Space: O(n)

# greedy, case works
# Reference: https://leetcode.com/problems/minimum-array-sum/solutions/6078002/o-n-log-n-greedy/
class Solution(object):
    def minArraySum(self, nums, k, op1, op2):
        """
        :type nums: List[int]
        :type k: int
        :type op1: int
        :type op2: int
        :rtype: int
        """
        nums.sort()

        left = next((i for i in xrange(len(nums)) if nums[i] >= k), len(nums))
        right = next((i for i in xrange(len(nums)) if nums[i] >= 2*k-1), len(nums))

        lookup, cnt = [False]*len(nums), 0
        for j in reversed(xrange(right, len(nums))):
            if not op1:
                break
            op1 -= 1
            nums[j] = (nums[j]+1)//2
            if op2:
                op2 -= 1
                nums[j] -= k
        else:
            j = right-1

        for i in xrange(left, j+1):
            if not op2:
                break
            op2 -= 1
            if k%2 == 1 and nums[i]%2 == 0:
                lookup[i] = True
            nums[i] -= k
        else:
            i = j+1
    
        for j in reversed(xrange(i, j+1)):
            if not op1:
                break
            op1 -= 1
            if k%2 == 1 and nums[j]%2 == 1:
                cnt += 1
            nums[j] = (nums[j]+1)//2
        else:
            j = i-1

        arr = sorted((nums[idx], idx) for idx in xrange(i))
        for _ in xrange(op1):
            x, idx = arr.pop()
            nums[idx] = (x+1)//2
            if cnt and lookup[idx]:
                cnt -= 1
                nums[idx] -= 1
        return sum(nums)


# Time:  O(n * op1 * op2)
# Space: O(op1 * op2)
# dp
class Solution2(object):
    def minArraySum(self, nums, k, op1, op2):
        """
        :type nums: List[int]
        :type k: int
        :type op1: int
        :type op2: int
        :rtype: int
        """
        dp = [[sum(nums)]*(op2+1) for _ in xrange(op1+1)]
        for x in nums:
            for i in reversed(xrange(op1+1)):
                for j in reversed(xrange(op2+1)):
                    if i-1 >= 0:
                        dp[i][j] = min(dp[i][j], dp[i-1][j]-x+(x+1)//2)
                    if j-1 >= 0:
                        if x-k >= 0:
                            dp[i][j] = min(dp[i][j], dp[i][j-1]-x+(x-k))
                    if i-1 >= 0 and j-1 >= 0:
                        if x-k >= 0:
                            dp[i][j] = min(dp[i][j], dp[i-1][j-1]-x+((x-k)+1)//2)
                        if (x+1)//2-k >= 0:
                            dp[i][j] = min(dp[i][j], dp[i-1][j-1]-x+((x+1)//2-k))
        return dp[op1][op2]
