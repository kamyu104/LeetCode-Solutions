# Time:  O(l * n)
# Space: O(n)

# greedy, bitmasks, sort
class Solution(object):
    def largestPower(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        L = 15
        result = []
        groups = [nums[:]]
        for i in reversed(xrange(L)):
            prefix = 0
            for j, group in enumerate(groups):
                ones = [x for x in group if x&(1<<i)]
                prefix += len(ones)
                if len(ones) != len(group):
                    if ones:
                        zeros = [x for x in group if not x&(1<<i)]
                        groups[j:j+1] = [ones, zeros]
                    break
            result.append(prefix)
        return result
