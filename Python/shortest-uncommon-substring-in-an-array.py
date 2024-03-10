# Time:  O(n * l^2)
# Space: O(t)

# trie
class Solution(object):
    def shortestSubstrings(self, arr):
        """
        :type arr: List[str]
        :rtype: List[str]
        """
        class Trie(object):
            def __init__(self):
                self.__nodes = []
                self.__cnts = []
                self.__new_node()
            
            def __new_node(self):
                self.__nodes.append([-1]*26)
                self.__cnts.append(0)
                return len(self.__nodes)-1

            def add(self, s, d):
                for i in xrange(len(s)):
                    curr = 0
                    for j in xrange(i, len(s)):
                        x = ord(s[j])-ord('a')
                        if self.__nodes[curr][x] == -1:
                            self.__nodes[curr][x] = self.__new_node()
                        curr = self.__nodes[curr][x]
                        self.__cnts[curr] += d
    
            def query(self, s):
                result = (float("inf"), "")
                for i in xrange(len(s)):
                    curr = 0
                    for j in xrange(i, len(s)):
                        curr = self.__nodes[curr][ord(s[j])-ord('a')]
                        if self.__cnts[curr] == 0:
                            result = min(result, (j-i+1, s[i:j+1]))
                            break
                return result[1]
    
        trie = Trie()
        for x in arr:
            trie.add(x, +1)
        result = []
        for x in arr:
            trie.add(x, -1)
            result.append(trie.query(x))
            trie.add(x, +1)
        return result
