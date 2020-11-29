# Time:  O(n + k)
# Space: O(k)

class Solution(object):
    def minMoves(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        delta = [0]*(2*(limit+1))
        for i in xrange(len(nums)//2):
            left, right = nums[i], nums[-1-i]
            delta[min(left, right)+1] -= 1        # if target total grows to min(left, right)+1, one less move
            delta[left+right] -= 1                # if target total grows to left+right, one less move
            delta[left+right+1] += 1              # if target total grows to left+right+1, one more move
            delta[max(left, right)+limit+1] += 1  # if target total grows to max(left, right)+limit+1, one more move
        result = count = len(nums)                # default is to move all nums
        for total in xrange(2, 2*limit+1):        # enumerate all possible target totals
            count += delta[total]
            result = min(result, count)
        return result
