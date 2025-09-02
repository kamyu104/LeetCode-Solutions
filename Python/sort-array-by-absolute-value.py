# Time:  O(n + r)
# Space: O(n + r)

# sort
class Solution(object):
    def sortByAbsoluteValue(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        mx = max(abs(x) for x in nums)
        lookup = [[] for _ in xrange(mx+1)]
        for x in nums:
            lookup[abs(x)].append(x)
        result = []
        for x in lookup:
            result.extend(x)
        return result


# Time:  O(nlogn)
# Space: O(1)
# sort
class Solution2(object):
    def sortByAbsoluteValue(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort(key=lambda x: abs(x))
        return nums
