# Time:  O(n)
# Space: O(t)

# simulation, trie
class Solution(object):
    def partitionString(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        class Trie(object):
            def __init__(self):
                self.__nodes = []
                self.__new_node()
                self.__curr = 0
            
            def __new_node(self):
                self.__nodes.append([-1]*26)
                return len(self.__nodes)-1

            def add(self, c):
                x = ord(c)-ord('a')
                if self.__nodes[self.__curr][x] == -1:
                    self.__nodes[self.__curr][x] = self.__new_node()
                    self.__curr = 0
                    return
                self.__curr = self.__nodes[self.__curr][x]

            def curr(self):
                return self.__curr

        result = []
        trie = Trie()
        curr = []
        for x in s:
            curr.append(x)
            trie.add(x)
            if trie.curr():
                continue
            result.append("".join(curr))
            curr = []
        return result
