# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findDifferentBinaryString(self, nums):
        """
        :type nums: List[str]
        :rtype: str
        """
        return "".join("01"[nums[i][i] == '0'] for i in xrange(len(nums)))


# Time:  O(k * n) = O(n^2), k is len(nums)
#                         , n is len(nums[0])
# Space: O(k) = O(n)
class Solution2(object):
    def findDifferentBinaryString(self, nums):
        """
        :type nums: List[str]
        :rtype: str
        """
        lookup = set(map(lambda x: int(x, 2), nums))  # Time: O(k * n) = O(n^2)
        return next(bin(i)[2:].zfill(len(nums[0])) for i in xrange(2**len(nums[0])) if i not in lookup)  # Time: O(k + n) = O(n)


# Time:  O(k * n + n * 2^n) = O(n * 2^n), k is len(nums)
#                                       , n is len(nums[0])
# Space: O(k) = O(1) ~ O(2^n)
class Solution_Extra(object):
    def findAllDifferentBinaryStrings(self, nums):
        """
        :type nums: List[str]
        :rtype: List[str]
        """
        lookup = set(map(lambda x: int(x, 2), nums))  # Time: O(k * n) = O(n * 2^n)
        return [bin(i)[2:].zfill(len(nums[0])) for i in xrange(2**len(nums[0])) if i not in lookup]  # Time: O(2^n + n * (2^n - k))
