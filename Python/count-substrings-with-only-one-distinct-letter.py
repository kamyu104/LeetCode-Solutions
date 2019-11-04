# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countLetters(self, S):
        """
        :type S: str
        :rtype: int
        """
        result = len(S)
        left = 0
        for right in xrange(1, len(S)):
            if S[right] == S[left]:
                result += right-left
            else:
                left = right
        return result
