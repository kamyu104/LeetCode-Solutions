# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        result, min_val, max_val = 0,  arrays[0][0], arrays[0][-1]
        for i in xrange(1, len(arrays)):
            result = max(result, \
                         max(max_val - arrays[i][0], \
                             arrays[i][-1] - min_val))
            min_val = min(min_val, arrays[i][0])
            max_val = max(max_val, arrays[i][-1])
        return result
