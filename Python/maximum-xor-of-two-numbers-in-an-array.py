# Time:  O(nlogk), k is max(nums)
# Space: O(n)

class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0

        for i in reversed(xrange(max(nums).bit_length())):
            result <<= 1
            prefixes = set()
            for n in nums:
                prefixes.add(n >> i)
            for p in prefixes:
                if (result | 1) ^ p in prefixes:
                    result |= 1
                    break

        return result


# Time:  O(nlogk), k is max(nums)
# Space: O(nlogk)
class Trie(object):
    def __init__(self, bit_length):
        self.__root = {}
        self.__bit_length = bit_length
        
    def insert(self, num):
        node = self.__root
        for i in reversed(xrange(self.__bit_length)):
            curr = (num>>i) & 1
            if curr not in node:
                node[curr] = {}
            node = node[curr]
                
    def query(self, num):
        if not self.__root: 
            return -1
        node, result = self.__root, 0
        for i in reversed(xrange(self.__bit_length)):
            curr = (num>>i) & 1
            if 1^curr in node:
                node = node[1^curr]
                result |= 1<<i
            else:
                node = node[curr]
        return result


class Solution2(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        trie = Trie(max(nums).bit_length())
        result = 0
        for num in nums:
            trie.insert(num)
            result = max(result, trie.query(num))
        return result
