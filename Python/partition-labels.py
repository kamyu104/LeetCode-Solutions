# Time:  O(n)
# Space: O(n)

class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        lookup = {c: i for i, c in enumerate(S)}
        first, last = 0, 0
        result = []
        for i, c in enumerate(S):
            last = max(last, lookup[c])
            if i == last:
                result.append(i-first+1)
                first = i+1
        return result

