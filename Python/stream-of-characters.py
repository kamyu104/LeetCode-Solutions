# Time:  ctor:  O(n)    , n is the total size of patterns
#        query: O(m + z), m is the total size of query string
#                       , z is the number of all matched strings
#                       , query time could be further improved to O(m) if we don't return all matched patterns
# Space: O(t), t is the total size of ac automata trie
#            , space could be further improved by DAT (double-array trie)

# Aho–Corasick automata
# reference:
# 1. http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Small02.pdf
# 2. http://algo.pw/algo/64/python

import collections


class AhoNode(object):
    def __init__(self):
        self.children = collections.defaultdict(AhoNode)
        self.indices = []
        self.suffix = None
        self.output = None


class AhoTrie(object):

    def step(self, letter):
        while self.__node and letter not in self.__node.children:
            self.__node = self.__node.suffix
        self.__node = self.__node.children[letter] if self.__node else self.__root
        return self.__get_ac_node_outputs(self.__node)
    
    def __init__(self, patterns):
        self.__root = self.__create_ac_trie(patterns)
        self.__node = self.__create_ac_suffix_and_output_links(self.__root)
    
    def __create_ac_trie(self, patterns):  # Time:  O(n), Space: O(t)
        root = AhoNode()
        for i, pattern in enumerate(patterns):
            node = root
            for c in pattern:
                node = node.children[c]
            node.indices.append(i)
        return root

    def __create_ac_suffix_and_output_links(self, root):  # Time:  O(n), Space: O(t)
        queue = collections.deque()
        for node in root.children.itervalues():
            queue.append(node)
            node.suffix = root

        while queue:
            node = queue.popleft()
            for c, child in node.children.iteritems():
                queue.append(child)
                suffix = node.suffix
                while suffix and c not in suffix.children:
                    suffix = suffix.suffix
                child.suffix = suffix.children[c] if suffix else root
                child.output = child.suffix if child.suffix.indices else child.suffix.output
                
        return root

    def __get_ac_node_outputs(self, node):  # Time:  O(z), in this question, it could be improved to O(1)
                                            # if we only return a matched pattern without all matched ones
        result = []
        for i in node.indices:
            result.append(i)
            # return result
        output = node.output
        while output:
            for i in output.indices:
                result.append(i)
                # return result
            output = output.output
        return result


class StreamChecker(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.__trie = AhoTrie(words)

    def query(self, letter):  # O(m) times
        """
        :type letter: str
        :rtype: bool
        """
        return len(self.__trie.step(letter)) > 0
        

# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
