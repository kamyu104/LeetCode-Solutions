# Time:  O(nlogn + mlogm)
# Space: O(n)

class Trie(object):
    def __init__(self):
        self.__root = {}
        
    def insert(self, num):
        node = self.__root
        for i in reversed(xrange(32)):
            curr = (num>>i) & 1
            if curr not in node:
                node[curr] = {}
            node = node[curr]
                
    def query(self, num):
        if not self.__root: 
            return -1
        node, result = self.__root, 0
        for i in reversed(xrange(32)):
            curr = (num>>i) & 1
            if 1^curr in node:
                node = node[1^curr]
                result |= 1<<i
            else:
                node = node[curr]
        return result


class Solution(object):
    def maximizeXor(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        nums.sort()
        queries = sorted(enumerate(queries), key=lambda x: x[1][1])
        trie = Trie()
        result = [-1]*len(queries)
        j = 0
        for i, (x, m) in queries:
            while j < len(nums) and nums[j] <= m:
                trie.insert(nums[j])
                j += 1
            result[i] = trie.query(x)
        return result
