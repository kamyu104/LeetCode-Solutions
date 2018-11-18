# Time:  O(n)
# Space: O(1)

class Solution(object):
    def diStringMatch(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        result = []
        left, right = 0, len(S)
        for c in S:
            if c == 'I':
                result.append(left)
                left += 1
            else:
                result.append(right)
                right -= 1
        result.append(left)
        return result
