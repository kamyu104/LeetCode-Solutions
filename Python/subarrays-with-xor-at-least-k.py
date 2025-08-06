# Time:  O(nlogr), r = max(max(nums), k, 1)
# Space: O(nlogr)

# bitmasks, prefix sum, trie
class Solution(object):
    def countXorSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        class Trie(object):
            def __init__(self, bit_length):
                self.__lefts = [-1]*(1+(1+len(nums))*bit_length)  # preallocate to speed up performance
                self.__rights = [-1]*(1+(1+len(nums))*bit_length)
                self.__cnts = [0]*(1+(1+len(nums))*bit_length)
                self.__i = 0
                self.__new_node()
                self.__bit_length = bit_length
            
            def __new_node(self):
                self.__i += 1
                return self.__i-1

            def add(self, num):
                curr = 0
                for i in reversed(xrange(self.__bit_length)):
                    x = (num>>i)&1
                    if x == 0:
                        if self.__lefts[curr] == -1:
                            self.__lefts[curr] = self.__new_node()
                        curr = self.__lefts[curr]
                    else:
                        if self.__rights[curr] == -1:
                            self.__rights[curr] = self.__new_node()
                        curr = self.__rights[curr]
                    self.__cnts[curr] += 1
                        
            def query(self, prefix, k):
                result = curr = 0
                for i in reversed(xrange(self.__bit_length)):
                    t = (k>>i)&1
                    x = (prefix>>i)&1
                    if t == 0:
                        tmp = self.__lefts[curr] if 1^x == 0 else self.__rights[curr]
                        if tmp != -1:
                            result += self.__cnts[tmp]
                    curr = self.__lefts[curr] if t^x == 0 else self.__rights[curr]
                    if curr == -1:
                        break
                else:
                    result += self.__cnts[curr]
                return result
    
        result = prefix = 0
        mx = max(max(nums), k, 1)
        trie = Trie(mx.bit_length())
        trie.add(prefix)
        for x in nums:
            prefix ^= x
            result += trie.query(prefix, k)
            trie.add(prefix)
        return result


# Time:  O(nlogr), r = max(max(nums), k, 1)
# Space: O(t)
# bitmasks, prefix sum, trie
class Solution_TLE(object):
    def countXorSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        class Trie(object):
            def __init__(self, bit_length):
                self.__nodes = []
                self.__cnts = []
                self.__new_node()
                self.__bit_length = bit_length
            
            def __new_node(self):
                self.__nodes.append([-1]*2)
                self.__cnts.append(0)
                return len(self.__nodes)-1

            def add(self, num):
                curr = 0
                for i in reversed(xrange(self.__bit_length)):
                    x = (num>>i)&1
                    if self.__nodes[curr][x] == -1:
                        self.__nodes[curr][x] = self.__new_node()
                    curr = self.__nodes[curr][x]
                    self.__cnts[curr] += 1
                        
            def query(self, prefix, k):
                result = curr = 0
                for i in reversed(xrange(self.__bit_length)):
                    t = (k>>i)&1
                    x = (prefix>>i)&1
                    if t == 0:
                        tmp = self.__nodes[curr][1^x]
                        if tmp != -1:
                            result += self.__cnts[tmp]
                    curr = self.__nodes[curr][t^x]
                    if curr == -1:
                        break
                else:
                    result += self.__cnts[curr]
                return result
        
        result = prefix = 0
        mx = max(max(nums), k, 1)
        trie = Trie(mx.bit_length())
        trie.add(prefix)
        for x in nums:
            prefix ^= x
            result += trie.query(prefix, k)
            trie.add(prefix)
        return result
