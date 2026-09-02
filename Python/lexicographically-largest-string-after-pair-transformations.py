# Time:  O(n * (r / 2^25 + 25)) = O(n)
# Space: O(1)

# greedy
class Solution(object):
    def largestString(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        def f(x):
            q, x = divmod(x, 1<<25)
            return "".join(['z']*q+[chr(ord('a')+i) for i in reversed(xrange(25)) if x&(1<<i)])

        return [f(x) for x in nums]
