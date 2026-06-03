# Time:  O(n)
# Space: O(n)

# hash table, prefix sum, greedy
class Solution(object):
    def maximumMEX(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        suffix = [0]*len(nums)
        ver = -1
        lookup = [ver]*len(nums)
        ver += 1
        mex = 0
        for i in reversed(xrange(len(nums))):
            if nums[i] < len(lookup):
                lookup[nums[i]] = ver
            while mex < len(lookup) and lookup[mex] == ver:
                mex += 1
            suffix[i] = mex
        ver += 1
        mex = 0
        result = []
        j = 0
        for i in xrange(len(nums)):
            if not suffix[j]:
                break
            if nums[i] < len(lookup):
                lookup[nums[i]] = ver
            while mex < len(lookup) and lookup[mex] == ver:
                mex += 1
            if mex != suffix[j]:
                continue
            ver += 1
            mex = 0
            result.append(suffix[j])
            j = i+1
        result.extend(0 for _ in xrange(len(nums)-j))
        return result
