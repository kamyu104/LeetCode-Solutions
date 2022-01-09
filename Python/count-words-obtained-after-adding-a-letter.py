# Time:  O(n)
# Space: O(n)

class Solution(object):
    def wordCount(self, startWords, targetWords):
        """
        :type startWords: List[str]
        :type targetWords: List[str]
        :rtype: int
        """
        def bitmask(w):
            return reduce(lambda x, y: x|y, (1 << (ord(c)-ord('a')) for i, c in enumerate(w)))

        lookup = set(bitmask(w) for w in startWords)
        result = 0 
        for w in targetWords: 
            mask = bitmask(w)
            result += any(mask ^ (1 << ord(c)-ord('a')) in lookup for c in w)
        return result 
