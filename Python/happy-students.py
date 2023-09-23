# Time:  O(n)
# Space: O(n)

# codeforce, https://codeforces.com/contest/1782/problem/B
# freq table
class Solution(object):
    def countWays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = [0]*(len(nums)+1)
        for x in nums:
            cnt[x] += 1
        result = prefix = 0
        for i in xrange(len(nums)+1):
            if prefix == i and cnt[i] == 0:
                result += 1
            prefix += cnt[i]
        return result


# Time:  O(nlogn)
# Space: O(1)
# codeforce, https://codeforces.com/contest/1782/problem/B
# sort, greedy
class Solution2(object):
    def countWays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return sum((i == 0 or nums[i-1] < i) and (i == len(nums) or nums[i] > i) for i in xrange(len(nums)+1))
