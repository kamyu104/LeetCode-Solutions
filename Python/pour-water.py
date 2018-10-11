# Time:  O(v * n)
# Space: O(1)

class Solution(object):
    def pourWater(self, heights, V, K):
        """
        :type heights: List[int]
        :type V: int
        :type K: int
        :rtype: List[int]
        """
        for _ in xrange(V):
            best = K
            for d in (-1, 1):
                i = K
                while 0 <= i+d < len(heights) and \
                      heights[i+d] <= heights[i]:
                    if heights[i+d] < heights[i]: best = i+d
                    i += d
                if best != K:
                    break
            heights[best] += 1
        return heights

