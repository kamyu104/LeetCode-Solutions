# Time:  O(nlogr + nlogn)
# Space: O(n)

# sort, bitmasks
class Solution(object):
    def sortByReflection(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def reverse(x):
            result = 0
            while x:
                result = (result<<1)|(x&1)
                x >>= 1
            return result

        return [x for _, x in sorted((reverse(x), x) for x in nums)]
