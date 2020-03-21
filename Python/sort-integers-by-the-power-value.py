# Time:  O(n) on average
# Space: O(n)

import random


class Solution(object):
    dp = {}

    def getKth(self, lo, hi, k):
        """
        :type lo: int
        :type hi: int
        :type k: int
        :rtype: int
        """
        def nth_element(nums, n, compare=lambda a, b: a < b):
            def partition_around_pivot(left, right, pivot_idx, nums, compare):
                new_pivot_idx = left
                nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
                for i in xrange(left, right):
                    if compare(nums[i], nums[right]):
                        nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                        new_pivot_idx += 1

                nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
                return new_pivot_idx

            left, right = 0, len(nums) - 1
            while left <= right:
                pivot_idx = random.randint(left, right)
                new_pivot_idx = partition_around_pivot(left, right, pivot_idx, nums, compare)
                if new_pivot_idx == n:
                    return
                elif new_pivot_idx > n:
                    right = new_pivot_idx - 1
                else:  # new_pivot_idx < n
                    left = new_pivot_idx + 1
                    
        def power_value(x):
            y, result = x, 0
            while x > 1 and x not in Solution.dp:
                result += 1
                if x%2:
                    x = 3*x + 1
                else:
                    x //= 2
            Solution.dp[y] = result + (Solution.dp[x] if x > 1 else 0)
            return Solution.dp[y], y
        
        arr = map(power_value, range(lo, hi+1))
        nth_element(arr, k-1)
        return arr[k-1][1]


# Time:  O(nlogn)
# Space: O(n)
class Solution2(object):
    dp = {}

    def getKth(self, lo, hi, k):
        """
        :type lo: int
        :type hi: int
        :type k: int
        :rtype: int
        """
        def power_value(x):
            y, result = x, 0
            while x > 1 and x not in Solution2.dp:
                result += 1
                if x%2:
                    x = 3*x + 1
                else:
                    x //= 2
            Solution2.dp[y] = result + (Solution2.dp[x] if x > 1 else 0)
            return Solution2.dp[y], y
        
        return sorted(range(lo, hi+1), key=power_value)[k-1]
