# Time:  O(n)
# Space: O(n)

class Solution(object):
    def minMoves(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def moves(i, j):
            return prefix[j+1]-prefix[i]

        idxs = [i for i, x in enumerate(nums) if x]
        prefix = [0]*(len(idxs)+1)
        for i in xrange(len(idxs)):
            prefix[i+1] = prefix[i]+idxs[i]
        result = float("inf")
        for i in xrange(len(idxs)-k+1):
            result = min(result, -moves(i, i+k//2-1) + moves(i+(k+1)//2, i+k-1))  # take each i+k//2 as median, find min dist to median
        result -= (k//2)*((k+1)//2)  # rollback extra moves to the expected positions
        return result
