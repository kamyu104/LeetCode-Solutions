# Time:  O(n^2)
# Space: O(t), t is the number of trie nodes

class Solution(object):
    def countDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        trie = {}
        for i in xrange(len(s)):
            curr = trie
            for j in xrange(i, len(s)):
                if s[j] not in curr:
                    count += 1
                    curr[s[j]] = {}
                curr = curr[s[j]]
        return count
