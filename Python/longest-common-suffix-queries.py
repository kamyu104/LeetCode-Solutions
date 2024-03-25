# Time:  O((n + q) * l)
# Space: O(t)

# trie
class Solution(object):
    def stringIndices(self, wordsContainer, wordsQuery):
        """
        :type wordsContainer: List[str]
        :type wordsQuery: List[str]
        :rtype: List[int]
        """
        INF = float("INF")
        class Trie(object):
            def __init__(self):
                self.__nodes = []
                self.__mns = []
                self.__new_node()
            
            def __new_node(self):
                self.__nodes.append([-1]*26)
                self.__mns.append((INF, INF))
                return len(self.__nodes)-1

            def add(self, i, w):
                curr = 0
                self.__mns[curr] = min(self.__mns[curr], (len(w), i))
                for c in reversed(w):
                    x = ord(c)-ord('a')
                    if self.__nodes[curr][x] == -1:
                        self.__nodes[curr][x] = self.__new_node()
                    curr = self.__nodes[curr][x]
                    self.__mns[curr] = min(self.__mns[curr], (len(w), i))
            
            def query(self, w):
                curr = 0
                for c in reversed(w):
                    x = ord(c)-ord('a')
                    if self.__nodes[curr][x] == -1:
                        break
                    curr = self.__nodes[curr][x]
                return self.__mns[curr][1]
    
        trie = Trie()
        for i, w in enumerate(wordsContainer): 
            trie.add(i, w)
        return [trie.query(w) for w in wordsQuery]
