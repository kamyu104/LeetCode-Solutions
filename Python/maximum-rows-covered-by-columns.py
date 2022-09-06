# Time:  O(m * n + m * C(n, k))
# Space: O(m)

# bitmasks, hakmem-175
class Solution(object):
    def maximumRows(self, matrix, numSelect):
        """
        :type matrix: List[List[int]]
        :type numSelect: int
        :rtype: int
        """
        def next_popcount(n):  # reference: https://massivealgorithms.blogspot.com/2014/06/hakmem-item-175.html
            lowest_bit = n&-n
            left_bits = n+lowest_bit
            changed_bits = n^left_bits
            right_bits = (changed_bits//lowest_bit)>>2
            return left_bits|right_bits

        masks = [reduce(lambda m, c: m|(matrix[r][-1-c]<<c), xrange(len(matrix[0])), 0) for r in xrange(len(matrix))]
        result = 0
        mask = (1<<numSelect)-1
        while mask < 1<<len(matrix[0]):
            result = max(result, sum((m&mask) == m for m in masks))
            mask = next_popcount(mask)
        return result
