# Time:  O(n)
# Space: O(1)

import string


class Solution(object):
    def uniqueLetterString(self, S):
        """
        :type S: str
        :rtype: int
        """
        M = 10**9 + 7
        index = {c: [-1, -1] for c in string.ascii_uppercase}
        result = 0
        for i, c in enumerate(S):
            k, j = index[c]
            result = (result + (i-j) * (j-k)) % M
            index[c] = [j, i]
        for c in index:
            k, j = index[c]
            result = (result + (len(S)-j) * (j-k)) % M
        return result

