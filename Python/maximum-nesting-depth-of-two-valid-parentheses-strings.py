# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxDepthAfterSplit(self, seq):
        """
        :type seq: str
        :rtype: List[int]
        """
        return [(i & 1) ^ (seq[i] == '(') for i, c in enumerate(seq)]


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def maxDepthAfterSplit(self, seq):
        """
        :type seq: str
        :rtype: List[int]
        """
        A, B = 0, 0
        result = [0]*len(seq)
        for i, c in enumerate(seq):
            point = 1 if c == '(' else -1
            if (point == 1 and A <= B) or \
               (point == -1 and A >= B):
                A += point
            else:
                B += point
                result[i] = 1
        return result
