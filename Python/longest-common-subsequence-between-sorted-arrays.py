# Time:  O(m * n)
# Space: O(l), l is min(len(arr) for arr in arrays)

class Solution(object):
    def longestCommomSubsequence(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: List[int]
        """
        result = min(arrays, key=lambda x: len(x))
        for arr in arrays:
            new_result = []
            i, j = 0, 0
            while i != len(result) and j != len(arr):
                if result[i] < arr[j]:
                    i += 1
                elif result[i] > arr[j]:
                    j += 1
                else:
                    new_result.append(result[i])
                    i += 1
                    j += 1
            result = new_result
        return result


# Time:  O(m * n)
# Space: O(k), k is min(m * n, max(x for arr in arrays for x in arr))
import collections


class Solution2(object):
    def longestCommomSubsequence(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: List[int]
        """
        return [num for num, cnt in collections.Counter(x for arr in arrays for x in arr).iteritems() if cnt == len(arrays)]
