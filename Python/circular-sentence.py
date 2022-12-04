# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def isCircularSentence(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        return sentence[0] == sentence[-1] and all(sentence[i-1] == sentence[i+1]for i in xrange(len(sentence)) if sentence[i] == ' ')
