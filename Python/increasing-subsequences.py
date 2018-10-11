# Time:  O(n * 2^n)
# Space: O(n), longest possible path in tree, which is if all numbers are increasing.

class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def findSubsequencesHelper(nums, pos, seq, result):
            if len(seq) >= 2:
                result.append(list(seq))
            lookup = set()
            for i in xrange(pos, len(nums)):
                if (not seq or nums[i] >= seq[-1]) and \
                   nums[i] not in lookup:
                    lookup.add(nums[i])
                    seq.append(nums[i])
                    findSubsequencesHelper(nums, i+1, seq, result)
                    seq.pop()

        result, seq = [], []
        findSubsequencesHelper(nums, 0, seq, result)
        return result

