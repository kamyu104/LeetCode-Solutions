# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def maximumEnergy(self, energy, k):
        """
        :type energy: List[int]
        :type k: int
        :rtype: int
        """
        result = float("-inf")
        for i in xrange(k):
            curr = 0
            for j in reversed(xrange(((len(energy)-i)-1)%k, len(energy)-i, k)):  # xrange(len(energy)-1-i, -1, -k)
                curr += energy[j]
                result = max(result, curr)
        return result
