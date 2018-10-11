# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        result = [1, 0]
        for c in S:
            w = widths[ord(c)-ord('a')]
            result[1] += w
            if result[1] > 100:
                result[0] += 1
                result[1] = w
        return result

