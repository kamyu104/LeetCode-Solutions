# Time:  O(nlogn + nlogk) = O(nlogn), k is the length of the result.
# Space: O(1)

# You have a number of envelopes with widths and heights given
# as a pair of integers (w, h). One envelope can fit into another
# if and only if both the width and height of one envelope is greater 
# than the width and height of the other envelope.
#
# What is the maximum number of envelopes can you Russian doll?
# (put one inside other)
#
# Example:
# Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number
# of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        def insert(target):
            left, right = 0, len(result) - 1
            while left <= right:
                mid = left + (right - left) / 2
                if result[mid] >= target:
                    right = mid - 1
                else:
                    left = mid + 1
            if left == len(result):
                result.append(target)
            else:
                result[left] = target

        envelopes.sort(lambda x, y: y[1] - x[1] if x[0] == y[0] \
                                    else x[0] - y[0])
        result, i = [], 0
        for envelope in envelopes:
            insert(envelope[1])
        return len(result)
