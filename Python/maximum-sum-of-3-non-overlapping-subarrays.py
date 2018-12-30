# Time:  O(n)
# Space: O(n)

class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n = len(nums)
        accu = [0]
        for num in nums:
            accu.append(accu[-1]+num)

        left_pos = [0] * n
        total = accu[k]-accu[0]
        for i in xrange(k, n):
            if accu[i+1]-accu[i+1-k] > total:
                left_pos[i] = i+1-k
                total = accu[i+1]-accu[i+1-k]
            else:
                left_pos[i] = left_pos[i-1]

        right_pos = [n-k] * n
        total = accu[n]-accu[n-k]
        for i in reversed(xrange(n-k)):
            if accu[i+k]-accu[i] > total:
                right_pos[i] = i
                total = accu[i+k]-accu[i]
            else:
                right_pos[i] = right_pos[i+1]

        result, max_sum = [], 0
        for i in xrange(k, n-2*k+1):
            left, right = left_pos[i-1], right_pos[i+k]
            total = (accu[i+k]-accu[i]) + \
                    (accu[left+k]-accu[left]) + \
                    (accu[right+k]-accu[right])
            if total > max_sum:
                max_sum = total
                result = [left, i, right]
        return result

