# Time:  O(n * m)
# Space: O(m)

# greedy
class Solution(object):
    def answerString(self, word, numFriends):
        """
        :type word: str
        :type numFriends: int
        :rtype: str
        """
        if numFriends == 1:
            return word
        m = len(word)-(numFriends-1)
        c = max(word)
        return max(word[i:i+m] for i in xrange(len(word)) if word[i] == c)
