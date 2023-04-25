# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def addMinimum(self, word):
        """
        :type word: str
        :rtype: int
        """
        return 3*(sum(i-1 < 0 or word[i-1] >= word[i] for i in xrange(len(word))))-len(word)
 
