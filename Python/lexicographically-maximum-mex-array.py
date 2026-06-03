# Time:  O(n)
# Space: O(n)

# hash table, prefix sum, greedy
class Solution(object):
    def maximumMEX(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ver = -1
        lookup = [ver]*len(nums)
        suffix = [0]*len(nums)
        ver += 1
        mex = 0
        for i in reversed(xrange(len(nums))):
            if nums[i] < len(lookup):
                lookup[nums[i]] = ver
            while mex < len(lookup) and lookup[mex] == ver:
                mex += 1
            suffix[i] = mex
        result = []
        ver += 1
        mex = 0
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
            result.append(mex)
            ver += 1
            mex = 0
            j = i+1
        result.extend(0 for _ in xrange(len(nums)-j))
        return result


# Time:  O(n)
# Space: O(n)
# hash table, freq table, greedy
class Solution2(object):
    def maximumMEX(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ver = -1
        lookup = [ver]*len(nums)
        cnt = [0]*len(nums)
        ver += 1
        mex = 0
        for i in xrange(len(nums)):
            if nums[i] < len(lookup):
                lookup[nums[i]] = ver
                cnt[nums[i]] += 1
            while mex < len(lookup) and lookup[mex] == ver:
                mex += 1
        new_suffix = suffix = mex
        result = []
        ver += 1
        mex = 0
        j = 0
        for i in xrange(len(nums)):
            if not suffix:
                break
            curr = 0
            if nums[i] < len(lookup):
                lookup[nums[i]] = ver
                cnt[nums[i]] -= 1
                if not cnt[nums[i]] and nums[i] < new_suffix:
                    new_suffix = nums[i]
            while mex < len(lookup) and lookup[mex] == ver:
                mex += 1
            if mex != suffix:
                continue
            result.append(mex)
            ver += 1
            mex = 0
            j = i+1
            suffix = new_suffix
        result.extend(0 for _ in xrange(len(nums)-j))
        return result
