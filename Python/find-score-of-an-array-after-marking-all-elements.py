# Time:  O(nlogn)
# Space: O(n)

# simulation, sort, hash table
class Solution(object):
    def findScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        idxs = range(len(nums))
        idxs.sort(key=lambda x: (nums[x], x))
        lookup = [False]*len(nums)
        result = 0
        for i in idxs:
            if lookup[i]:
                continue
            lookup[i] = True
            if i-1 >= 0:
                lookup[i-1] = True
            if i+1 < len(lookup):
                lookup[i+1] = True
            result += nums[i]
        return result
