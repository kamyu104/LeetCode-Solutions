# Time:  O(n * w * l)
# Space: O(l)

import itertools


# dp
class Solution(object):
    def minimumCost(self, target, words, costs):
        """
        :type target: str
        :type words: List[str]
        :type costs: List[int]
        :rtype: int
        """
        INF = float("inf")
        l = max(len(w) for w in words)
        dp = [INF]*(l+1)
        dp[0] = 0
        for i in xrange(len(target)):
            if dp[i%len(dp)] == INF:
                continue
            for w, c in itertools.izip(words, costs):
                if target[i:i+len(w)] == w:
                    dp[(i+len(w))%len(dp)] = min(dp[(i+len(w))%len(dp)], dp[i%len(dp)]+c)
            dp[i%len(dp)] = INF
        return dp[len(target)%len(dp)] if dp[len(target)%len(dp)] != INF else -1


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
        def query(i):
            curr = trie
            for j in xrange(i, len(target)):
                x = target[j]
                if x not in curr:
                    break
                curr = curr[x]
                if "_end" in curr:
                    dp[j+1] = min(dp[j+1], dp[i]+curr["_end"])

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
            query(i)
        return dp[-1] if dp[-1] != INF else -1


# Time:  O(n^2 + w * l)
# Space: O(t)
import itertools


# trie, dp
class Solution3(object):
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
                self.__nodes = []
                self.__mns = []
                self.__new_node()
            
            def __new_node(self):
                self.__nodes.append([-1]*26)
                self.__mns.append(INF)
                return len(self.__nodes)-1

            def add(self, w, c):
                curr = 0
                for x in w:
                    x = ord(x)-ord('a')
                    if self.__nodes[curr][x] == -1:
                        self.__nodes[curr][x] = self.__new_node()
                    curr = self.__nodes[curr][x]
                self.__mns[curr] = min(self.__mns[curr], c)
            
            def query(self, i):
                curr = 0
                for j in xrange(i, len(target)):
                    x = ord(target[j])-ord('a')
                    if self.__nodes[curr][x] == -1:
                        break
                    curr = self.__nodes[curr][x]
                    if self.__mns[curr] != INF:
                        dp[j+1] = min(dp[j+1], dp[i]+self.__mns[curr])
    
        trie = Trie()
        for w, c in itertools.izip(words, costs):
            trie.add(w, c)
        dp = [INF]*(len(target)+1)
        dp[0] = 0
        for i in xrange(len(target)):
            if dp[i] == INF:
                continue
            trie.query(i)
        return dp[-1] if dp[-1] != INF else -1
