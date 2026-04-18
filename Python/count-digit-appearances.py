# Time:  O(nlogr)
# Space: O(1)

# math
class Solution(object):
    def countDigitOccurrences(self, nums, digit):
        """
        :type nums: List[int]
        :type digit: int
        :rtype: int
        """
        def count(x):
            result = 0
            while x:
                x, r = divmod(x, 10)
                if r == digit:
                    result += 1
            return result

        return sum(count(x) for x in nums)


# Time:  O(nlogr)
# Space: O(logr)
# math
class Solution2(object):
    def countDigitOccurrences(self, nums, digit):
        """
        :type nums: List[int]
        :type digit: int
        :rtype: int
        """
        return sum(str(x).count(str(digit)) for x in nums)
