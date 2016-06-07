# Time:  O(nlogn + nlogk) = O(nlogn)
# Space: O(k),  k is the max size of heights with the same width.

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
        :type envelopes: max_envelopest[max_envelopest[int]]
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

        envelopes.sort()
        result, i = [], 0
        while i < len(envelopes):
            w = envelopes[i][0]
            same_count = 0
            while i < len(envelopes) and envelopes[i][0] == w:
                i += 1
                same_count += 1

            for j in reversed(xrange(i-same_count, i)):  # Insert from larger h.
                insert(envelopes[j][1])

        return len(result)
