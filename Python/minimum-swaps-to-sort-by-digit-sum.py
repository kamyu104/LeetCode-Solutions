# Time:  O(nlogr + nlogn)
# Space: O(n)

# sort
class Solution(object):
    def minSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def total(x):
            result = 0
            while x:
                result += x%10
                x //= 10
            return result

        totals = map(total, nums)
        idxs = range(len(nums))
        idxs.sort(key=lambda i: (totals[i], nums[i]))
        i_to_idx = [-1]*len(idxs)
        for idx, x in enumerate(idxs):
            i_to_idx[x] = idx
        result = 0
        lookup = [False]*len(nums)
        for i in xrange(len(nums)):
            l = 0
            while not lookup[i]:
                lookup[i] = True
                l += 1
                i = i_to_idx[i]
            result += max(l-1, 0)
        return result
