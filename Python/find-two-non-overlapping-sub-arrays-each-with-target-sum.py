# Time:  O(n)
# Space: O(n)

class Solution(object):
    def minSumOfLengths(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        prefix, dp = {0: -1}, [0]*len(arr)  # dp[i], min len of target subarray until i
        result = min_len = float("inf")
        accu = 0
        for right in xrange(len(arr)):
            accu += arr[right]
            prefix[accu] = right
            if accu-target in prefix:
                left = prefix[accu-target]
                min_len = min(min_len, right-left)
                if left != -1:
                    result = min(result, dp[left] + (right-left))
            dp[right] = min_len
        return result if result != float("inf") else -1
