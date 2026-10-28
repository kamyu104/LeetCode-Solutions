# Time:  O(n * l + k * t + n * l * k + n * 2^k + n * l * logk + nlogn) = O(n * l + nlogn), k = 10
# Space: O(k * t + n + k * 2^k) = O(t)

import bisect


class Trie(object):
    def __init__(self):
        self.__nodes = []
        self.__new_node()
    
    def __new_node(self):
        self.__nodes.append([-1]*(10+1))
        return len(self.__nodes)-1

    def add(self, w, i):
        curr = 0
        for c in w:
            x = ord(c)-ord('a')
            if self.__nodes[curr][x] == -1:
                self.__nodes[curr][x] = self.__new_node()
            curr = self.__nodes[curr][x]
        self.__nodes[curr][-1] = i

    def nodes(self):
        return self.__nodes


def merge(lists):
    min_heap = [(x[0], i, 0) for i, x in enumerate(lists)]
    heapq.heapify(min_heap)
    result = []
    while min_heap:
        x, i, j = heapq.heappop(min_heap)
        result.append(x)
        if j+1 < len(lists[i]):
            heapq.heappush(min_heap, (lists[i][j+1], i, j+1))
    return result


# trie, tree dp, bitmask, heap
class Solution(object):
    def minInversions(self, words, target):
        """
        :type words: List[str]
        :type target: List[int]
        :rtype: int
        """
        lookup = [0]*len(words)
        for i in xrange(len(words)):
            lookup[target[i]] = i
        trie = Trie()
        for i, w in enumerate(words):
            trie.add(w, i)
        nodes = trie.nodes()
        result = 0
        merged = [None]*len(nodes)
        for u in reversed(xrange(len(nodes))):
            lists = []
            for i in xrange(len(nodes[u])-1):
                v = nodes[u][i]
                if v == -1:
                    continue
                lists.append(merged[v])
                merged[v] = None
            if len(lists) >= 2:
                cost = [[0]*len(lists) for _ in xrange(len(lists))]
                for a in xrange(len(lists)):  # Total Time: O(k * n * l)
                    for b in xrange(a+1, len(lists)):
                        cnt = i = 0
                        for x in lists[a]:
                            while i < len(lists[b]) and lists[b][i] < x:
                                i += 1
                            cnt += i
                        cost[a][b] = cnt
                        cost[b][a] = len(lists[a])*len(lists[b])-cnt
                dp, cost_total = [0]*(1<<len(lists)), [[0]*len(lists)]*(1<<len(lists))
                for mask in xrange(1, len(dp)):  # Total Time: O(k * 2^k * ((n - 1) / (k - 1))) = O(n * 2^k)
                    low = mask&-mask
                    cost_total[mask] = [cost_total[mask^low][c]+cost[low.bit_length()-1][c] for c in xrange(len(lists))]
                    dp[mask] = min(dp[mask^(1<<c)]+cost_total[mask^(1<<c)][c] for c in xrange(len(lists)) if mask&(1<<c))
                result += dp[-1]
            idx = nodes[u][-1]
            if idx != -1:
                lists.append([lookup[idx]])
            merged[u] = merge(lists)  # Totoal Time: O(n * l * logk)
            if idx != -1:  # Total Time: O(nlogn)
                result += bisect.bisect_left(merged[u], lookup[idx])
        return result
