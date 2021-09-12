# Time:  O(n)
# Space: O(1)

class Solution(object):
    def reversePrefix(self, word, ch):
        """
        :type word: str
        :type ch: str
        :rtype: str
        """
        i = word.find(ch)
        return word[:i+1][::-1]+word[i+1:]
