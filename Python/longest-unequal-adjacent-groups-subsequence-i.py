# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def getWordsInLongestSubsequence(self, n, words, groups):
        """
        :type n: int
        :type words: List[str]
        :type groups: List[int]
        :rtype: List[str]
        """
        return [words[i] for i in xrange(n) if i == 0 or groups[i-1] != groups[i]]
