# Time:  O(l * nlogn)
# Space: O(1)

# sort
class Solution(object):
    def phonePrefix(self, numbers):
        """
        :type numbers: List[str]
        :rtype: bool
        """
        numbers.sort()
        return all(not numbers[i+1].startswith(numbers[i]) for i in xrange(len(numbers)-1))


# Time:  O(n * l)
# Space: O(t)
# trie
class Solution2(object):
    def phonePrefix(self, numbers):
        """
        :type numbers: List[str]
        :rtype: bool
        """
        class Trie(object):
            def __init__(self):
                self.__nodes = []
                self.__new_node()
            
            def __new_node(self):
                self.__nodes.append([-1]*(10+1))
                return len(self.__nodes)-1

            def add(self, s):
                made = False
                curr = 0
                for i in xrange(len(s)):
                    x = ord(s[i])-ord('0')
                    if self.__nodes[curr][x] == -1:
                        self.__nodes[curr][x] = self.__new_node()
                        made = True
                    elif self.__nodes[self.__nodes[curr][x]][-1] == True:
                        return False
                    curr = self.__nodes[curr][x]
                self.__nodes[curr][-1] = True
                return made
    
        trie = Trie()
        return all(trie.add(x) for x in numbers)
