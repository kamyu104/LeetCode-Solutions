# Time:  O(n)
# Space: O(n)

import collections


# dp solution
class Solution(object):
    def countPairs(self, nums, low, high):
        """
        :type nums: List[int]
        :type low: int
        :type high: int
        :rtype: int
        """
        def count(nums, x):
            result = 0
            dp = collections.Counter(nums)
            while x:
                if x&1:
                    result += sum(dp[(x^1)^k]*dp[k] for k in dp.iterkeys())//2  # current limit is xxxxx1*****, count xor pair with xxxxx0***** pattern
                dp = collections.Counter({k>>1: dp[k]+dp[k^1] for k in dp.iterkeys()})
                x >>= 1
            return result
    
        return count(nums, high+1)-count(nums, low)


# Time:  O(n)
# Space: O(n)
# trie solution
class Trie(object):
    def __init__(self):
        self.__root = {}
        
    def insert(self, num):
        node = self.__root
        for i in reversed(xrange(32)):
            curr = (num>>i) & 1
            if curr not in node:
                node[curr] = {"_count":0}
            node = node[curr]
            node["_count"] += 1
                
    def query(self, num, limit):
        node, result = self.__root, 0
        for i in reversed(xrange(32)):
            curr = (num>>i) & 1
            bit = (limit>>i) & 1
            if bit:
                if curr in node:
                    result += node[0^curr]["_count"]  # current limit is xxxxx1*****, count xor pair with xxxxx0***** pattern
            if bit^curr not in node:
                break
            node = node[bit^curr]
        return result


class Solution2(object):
    def countPairs(self, nums, low, high):
        """
        :type nums: List[int]
        :type low: int
        :type high: int
        :rtype: int
        """
        result = 0
        trie = Trie()
        for x in nums:
            result += trie.query(x, high+1)-trie.query(x, low)
            trie.insert(x)
        return result
