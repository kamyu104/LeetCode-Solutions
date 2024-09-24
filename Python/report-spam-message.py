# Time:  O(n + m)
# Space: O(m)

# hash table
class Solution(object):
    def reportSpam(self, message, bannedWords):
        """
        :type message: List[str]
        :type bannedWords: List[str]
        :rtype: bool
        """
        THRESHOLD = 2
        lookup = set(bannedWords)
        return sum(m in lookup for m in message) >= THRESHOLD
