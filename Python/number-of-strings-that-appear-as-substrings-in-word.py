# Time:  O(n * l + m), n is the number of patterns
#                    , l is the max length of patterns
#                    , m is the length of word     
# Space: O(t)        , t is the total size of ac automata trie

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
        self.__lookup = set()  # modified
    
    def __create_ac_trie(self, patterns):  # Time: O(n * l), Space: O(t)
        root = AhoNode()
        for i, pattern in enumerate(patterns):
            node = root
            for c in pattern:
                node = node.children[c]
            node.indices.append(i)
        return root

    def __create_ac_suffix_and_output_links(self, root):  # Time: O(n * l), Space: O(t)
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

    def __get_ac_node_outputs(self, node):  # Total Time: O(n), modified
        result = []
        if node not in self.__lookup:  # modified
            self.__lookup.add(node)  # modified
            for i in node.indices:
                result.append(i)
            output = node.output
            while output and output not in self.__lookup:  # modified
                self.__lookup.add(output)  # modified
                for i in output.indices:
                    result.append(i)
                output = output.output
        return result


# ac automata solution
class Solution(object):
    def numOfStrings(self, patterns, word):
        """
        :type patterns: List[str]
        :type word: str
        :rtype: int
        """
        trie = AhoTrie(patterns)
        return sum(len(trie.step(c)) for c in word)


# Time:  O(n * (l + m)), n is the number of patterns
#                      , l is the max length of patterns
#                      , m is the length of word
# Space: O(l)
# kmp solution
class Solution2(object):
    def numOfStrings(self, patterns, word):
        """
        :type patterns: List[str]
        :type word: str
        :rtype: int
        """
        def getPrefix(pattern):
            prefix = [-1]*len(pattern)
            j = -1
            for i in xrange(1, len(pattern)):
                while j != -1 and pattern[j+1] != pattern[i]:
                    j = prefix[j]
                if pattern[j+1] == pattern[i]:
                    j += 1
                prefix[i] = j
            return prefix
            
        def kmp(text, pattern):
            if not pattern:
                return 0
            prefix = getPrefix(pattern)
            if len(text) < len(pattern):
                return -1
            j = -1
            for i in xrange(len(text)):
                while j != -1 and pattern[j+1] != text[i]:
                    j = prefix[j]
                if pattern[j+1] == text[i]:
                    j += 1
                if j+1 == len(pattern):
                    return i-j
            return -1
        
        return sum(kmp(word, pattern) != -1 for pattern in patterns)


# Time:  O(n * m * l), n is the number of patterns
#                    , l is the max length of patterns
#                    , m is the length of word
# Space: O(1)
# built-in solution
class Solution3(object):
    def numOfStrings(self, patterns, word):
        return sum(pattern in word for pattern in patterns)
