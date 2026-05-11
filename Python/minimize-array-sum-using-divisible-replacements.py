# Time:  O(n + rlogr), r = max(nums)
# Space: O(r)

# number theory
class Solution(object):
    def minArraySum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx = max(nums)
        lookup = [0]*(mx+1)
        for x in nums:
            lookup[x] = x
        for i in xrange(1, mx+1):
            if not lookup[i]:
                continue
            for j in xrange(i+i, mx+1, i):
                if lookup[j] == j:
                    lookup[j] = i
        return sum(lookup[x] for x in nums)
