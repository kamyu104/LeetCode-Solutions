# Time:  O(n^2 + w * l)
# Space: O(t)

import itertools


# trie, dp
class Solution(object):
    def minimumCost(self, target, words, costs):
        """
        :type target: str
        :type words: List[str]
        :type costs: List[int]
        :rtype: int
        """
        INF = float("inf")
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        for w, c in itertools.izip(words, costs):
            node = reduce(dict.__getitem__, w, trie)
            if "_end" not in node:
                node["_end"] = INF
            node["_end"] = min(node["_end"], c)
        dp = [INF]*(len(target)+1)
        dp[0] = 0
        for i in xrange(len(target)):
            if dp[i] == INF:
                continue
            curr = trie
            for j in xrange(i, len(target)):
                x = target[j]
                if x not in curr:
                    break
                curr = curr[x]
                if "_end" in curr:
                    dp[j+1] = min(dp[j+1], dp[i]+curr["_end"])
        return dp[-1] if dp[-1] != INF else -1


# Time:  O(n^2 + w * l)
# Space: O(t)
import itertools


# trie, dp
class Solution2(object):
    def minimumCost(self, target, words, costs):
        """
        :type target: str
        :type words: List[str]
        :type costs: List[int]
        :rtype: int
        """
        INF = float("inf")
        class Trie(object):
            def __init__(self):
                self.nodes = []
                self.mns = []
                self.__new_node()
            
            def __new_node(self):
                self.nodes.append([-1]*26)
                self.mns.append(INF)
                return len(self.nodes)-1

            def add(self, w, c):
                curr = 0
                for x in w:
                    x = ord(x)-ord('a')
                    if self.nodes[curr][x] == -1:
                        self.nodes[curr][x] = self.__new_node()
                    curr = self.nodes[curr][x]
                self.mns[curr] = min(self.mns[curr], c)

        trie = Trie()
        for w, c in itertools.izip(words, costs):
            trie.add(w, c)
        dp = [INF]*(len(target)+1)
        dp[0] = 0
        for i in xrange(len(target)):
            if dp[i] == INF:
                continue
            curr = 0
            for j in xrange(i, len(target)):
                x = ord(target[j])-ord('a')
                if trie.nodes[curr][x] == -1:
                    break
                curr = trie.nodes[curr][x]
                if trie.mns[curr] != INF:
                    dp[j+1] = min(dp[j+1], dp[i]+trie.mns[curr])
        return dp[-1] if dp[-1] != INF else -1
