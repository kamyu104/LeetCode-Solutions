# Time:  O(n)
# Space: O(n)

class Solution(object):
    def longestWPI(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        result, accu = 0, 0
        lookup = {}
        for i, h in enumerate(hours):
            accu = accu+1 if h > 8 else accu-1
            if accu > 0:
                result = i+1
            elif accu-1 in lookup:
                # lookup[accu-1] is the leftmost idx with smaller accu,
                # because for i from 1 to some positive k,
                # lookup[accu-i] is a strickly increasing sequence
                result = max(result, i-lookup[accu-1])
            lookup.setdefault(accu, i)
        return result
