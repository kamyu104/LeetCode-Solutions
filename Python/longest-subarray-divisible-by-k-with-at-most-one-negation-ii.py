# Time:  O(n + k^2)
# Space: O(k)

# prefix sum, hash table
class Solution(object):
    def longestSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        lookup = [0]
        left = [-1]*k
        left[0] = 0
        idxs = [0]*k
        mn = [float("inf")]*k
        prefix = result = 0
        for right, x in enumerate(nums):
            v = 2*x%k
            for i in xrange(idxs[v], len(lookup)):
                mn[(lookup[i]+v)%k] = min(mn[(lookup[i]+v)%k], left[lookup[i]])
            idxs[v] = len(lookup)
            prefix = (prefix+x)%k
            if left[prefix] != -1:
                result = max(result, right-left[prefix]+1)
            else:
                left[prefix] = right+1
                lookup.append(prefix)
            result = max(result, right-mn[prefix]+1)
        return result
