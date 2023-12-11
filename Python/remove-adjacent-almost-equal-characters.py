# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def removeAlmostEqualCharacters(self, word):
        """
        :type word: str
        :rtype: int
        """
        result = 0
        for i in xrange(len(word)-1):
            if (i+1)+result >= len(word):
                break
            if abs(ord(word[(i+1)+result])-ord(word[i+result])) <= 1:
                result += 1
        return result
