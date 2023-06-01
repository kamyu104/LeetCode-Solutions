# Time:  O((n + m) * l), l is max(len(w) for w in dictionary)
# Space: O(n + t)

import collections


# trie, dp
class Solution(object):
    def minExtraChar(self, s, dictionary):
        """
        :type s: str
        :type dictionary: List[str]
        :rtype: int
        """
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        for word in dictionary:
            reduce(dict.__getitem__, word, trie).setdefault("_end")
        dp = [float("inf")]*(len(s)+1)
        dp[0] = 0
        for i in xrange(len(s)):
            dp[i+1] = min(dp[i+1], dp[i]+1)
            curr = trie
            for j in xrange(i, len(s)):
                if s[j] not in curr:
                    break
                curr = curr[s[j]]
                if "_end" in curr:
                    dp[j+1] = min(dp[j+1], dp[i])
        return dp[-1]
