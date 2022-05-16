# Time:  O(nlogr), r is the max of candidates
# Space: O(logr)

# bit manipulation, freq table
class Solution(object):
    def largestCombination(self, candidates):
        """
        :type candidates: List[int]
        :rtype: int
        """
        cnt = []
        base, mx = 1, max(candidates)
        while base <= mx:
            cnt.append(sum(x&base > 0 for x in candidates))
            base <<= 1
        return max(cnt)
