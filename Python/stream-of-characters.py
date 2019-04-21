# Time:  ctor:  O(n), n is the total size of patterns
#        query: O(m + z), m is the total size of query string
#                       , z is the number of all matched strings 
# Space: O(t), t is the total size of ac automata trie

# Aho–Corasick automata
# reference:
# * http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Small02.pdf
# * http://algo.pw/algo/64/python

import collections


class AhoNode:
    def __init__(self):
        self.states = collections.defaultdict(AhoNode)
        self.output = None
        self.suffix = None
        self.id = None


def create_ac_trie(patterns):  # Time:  O(n), Space: O(t)
    root = AhoNode()
    for i, pattern in enumerate(patterns):
        node = root
        for c in pattern:
            node = node.states[c]
        node.id = i
    return root
 

def create_ac_suffix_and_output_links(root):  # Time:  O(n), Space: O(t)
    queue = collections.deque()
    for node in root.states.itervalues():
        queue.append(node)
        node.suffix = root
 
    while queue:
        rnode = queue.popleft()
        for key, child in rnode.states.iteritems():
            queue.append(child)
            fnode = rnode.suffix
            while fnode and key not in fnode.states:
                fnode = fnode.suffix
            child.suffix = fnode.states[key] if fnode else root
            child.output = child.suffix if child.suffix.id is not None else child.suffix.output


def create_ac_automata(patterns):
    root = create_ac_trie(patterns)
    create_ac_suffix_and_output_links(root)
    return root


class StreamChecker(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.__root = create_ac_automata(words)
        self.__node = self.__root
        self.__words = words

    def query(self, letter):
        """
        :type letter: str
        :rtype: bool
        """
        while self.__node and letter not in self.__node.states:
            self.__node = self.__node.suffix
        if not self.__node:
            self.__node = self.__root
            return
        self.__node = self.__node.states[letter]
        found = False
        if self.__node.id is not None:
            print self.__words[self.__node.id]
            found = True
        tmp = self.__node.output
        while tmp:
            print self.__words[tmp.id]
            tmp = tmp.output
            found = True
        return found

# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
