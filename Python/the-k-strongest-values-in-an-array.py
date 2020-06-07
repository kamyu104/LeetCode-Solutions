# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def getStrongest(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        arr.sort()
        m = arr[(len(arr)-1)//2]
        result = []
        left, right = 0, len(arr)-1
        while len(result) < k:
            if m-arr[left] > arr[right]-m:
                result.append(arr[left])
                left += 1
            else:
                result.append(arr[right])
                right -= 1
        return result


# Time:  O(nlogn)
# Space: O(1)
class Solution2(object):
    def getStrongest(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        arr.sort()
        m = arr[(len(arr)-1)//2]
        arr.sort(key=lambda x: (-abs(x-m), -x))
        return arr[:k]


# Time:  O(n)
# Space: O(1)
import random


class Solution_TLE(object):
    def getStrongest(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
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
        
        nth_element(arr, (len(arr)-1)//2)
        m = arr[(len(arr)-1)//2]
        nth_element(arr, k, lambda a, b: abs(a-m) > abs(b-m) if abs(a-m) != abs(b-m) else a > b)
        return arr[:k]
