# Time:  O(n)
# Space: O(n)

import random


class Solution(object):
    lookup = {}

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
                    
        def collatz_steps(x):
            y = x
            if x not in Solution.lookup:
                result = 0
                while x > 1:
                    result += 1
                    if x%2:
                        x = 3*x + 1
                    else:
                        x //= 2
                Solution.lookup[y] = result
            return Solution.lookup[y], y
        
        arr = map(collatz_steps, range(lo, hi+1))
        nth_element(arr, k-1)
        return arr[k-1][1]


# Time:  O(nlogn)
# Space: O(n)
class Solution2(object):
    lookup = {}

    def getKth(self, lo, hi, k):
        """
        :type lo: int
        :type hi: int
        :type k: int
        :rtype: int
        """
        def collatz_steps(x):
            y = x
            if x not in Solution2.lookup:
                result = 0
                while x > 1:
                    result += 1
                    if x%2:
                        x = 3*x + 1
                    else:
                        x //= 2
                Solution2.lookup[y] = result
            return Solution2.lookup[y], y
        
        return sorted(range(lo, hi+1), key=collatz_steps)[k-1]
