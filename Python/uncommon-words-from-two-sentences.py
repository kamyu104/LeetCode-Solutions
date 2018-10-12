# Time:  O(m + n)
# Space: O(m + n)

import collections

    
class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        count = collections.Counter(A.split())
        count += collections.Counter(B.split())
        return [word for word in count if count[word] == 1]

