# Time:  O(n)
# Space: O(1)

class Solution(object):
    def sortTransformedArray(self, nums, a, b, c):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        f = lambda x, a, b, c : a * x * x + b * x + c

        result = []
        if not nums:
            return result

        left, right = 0, len(nums) - 1
        if a > 0:
            while left <= right:
                if f(nums[left], a, b, c) > f(nums[right], a, b, c):
                    result.append(f(nums[left], a, b, c))
                    left += 1
                else:
                    result.append(f(nums[right], a, b, c))
                    right -= 1
        else:
            while left <= right:
                if f(nums[left], a, b, c) < f(nums[right], a, b, c):
                    result.append(f(nums[left], a, b, c))
                    left += 1
                else:
                    result.append(f(nums[right], a, b, c))
                    right -= 1

        return result if a <= 0 else result[::-1]
